#include "Connection.h"
#include "CServer.h"
#include "LogicSystem.h"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <string.h>
#include <iostream>

using namespace std;
const int HEAD_LEN = 4;
const int HEAD_ID_LEN = 2;
const int HEAD_DATA_LEN = 2;

Connection::Connection(boost::asio::io_context& ioc, CServer* server)
	:socket_(ioc),
	data_{ 0 },
	server_(server),
	closed_(false),
	ParsedHeadr_(false),
	HeaderNode_(make_shared<MessageNode>(HEAD_LEN))
{
	boost::uuids::uuid uuid = boost::uuids::random_generator()();
	uuid_ = boost::uuids::to_string(uuid);
}

void Connection::start()
{
	AsyncReadHeader(HEAD_LEN);
}

void Connection::close()
{
	socket_.close();
	closed_ = true;
}

tcp::socket& Connection::socket()
{
	return socket_;
}

string& Connection::uuid()
{
	return uuid_;
}

CServer* Connection::server()
{
	return server_;
}

void Connection::AsyncReadHeader(int len)
{
	auto self = shared_from_this();
	AsyncReadAll(len, [self, this, len](const boost::system::error_code& ec, std::size_t bytes_transfered) {
		try
		{
			if (ec)
			{
				cout << "Read Header Error: " << ec.what() << endl;
				close();
				server_->RemoveConnetion(uuid_);
				return;
			}
			if (bytes_transfered < len)
			{
				cout << "HeaderRead " << bytes_transfered << " bytes instead of " << len << endl;
				close();
				server_->RemoveConnetion(uuid_);
				return;
			}
			HeaderNode_->clear();
			memcpy(HeaderNode_->data_, data_, bytes_transfered);

			unsigned short id;
			unsigned short DataLen;
			memcpy(&id, HeaderNode_->data_, HEAD_ID_LEN);
			memcpy(&DataLen, HeaderNode_->data_ + HEAD_ID_LEN, HEAD_DATA_LEN);
			id = boost::asio::detail::socket_ops::network_to_host_short(id);
			DataLen = boost::asio::detail::socket_ops::network_to_host_short(DataLen);

			ReceiveNode_ = make_shared<ReceiveNode>(DataLen, id);
			AsyncReadBody(DataLen);
		}
		catch (exception& e)
		{
			cout << "Read Header Exception: " << e.what() << endl;
		}
		});
}

void Connection::AsyncReadBody(int len)
{
	auto self = shared_from_this();
	AsyncReadAll(len, [self, this, len](const boost::system::error_code& ec, std::size_t bytes_transfered) {
		try
		{
			if (ec)
			{
				cout << "Read Body Error: " << ec.what() << endl;
				close();
				server_->RemoveConnetion(uuid_);
				return;
			}
			if (bytes_transfered < len)
			{
				cout << "BodyRead " << bytes_transfered << " bytes instead of " << len << endl;
				close();
				server_->RemoveConnetion(uuid_);
				return;
			}
			memcpy(ReceiveNode_->data_, data_, bytes_transfered);
			ReceiveNode_->CurentIndex_ += bytes_transfered;
			ReceiveNode_->data_[ReceiveNode_->length_] = '\0';
			//Debug
			cout << "received: " << ReceiveNode_->data_ << endl;
			LogicSystem::Instance().post(make_shared<LogicNode>(self, ReceiveNode_));
			AsyncReadHeader(HEAD_LEN);
		}
		catch (exception& e)
		{
			cout << "Read Body Exception: " << e.what() << endl;
		}
		});
}

void Connection::send(const std::string& msg, unsigned short id)
{
	send(msg.c_str(), msg.size(), id);
}

void Connection::send(const char* msg, int len, unsigned short id)
{
	lock_guard<mutex> lock(mutex_);
	int size = queue_.size();
	queue_.emplace(make_shared<SendNode>(msg, len, id));
	if (size > 0) return;
	auto node = queue_.front();
	boost::asio::async_write(socket_, boost::asio::buffer(node->data_, node->length_),
		bind(&Connection::HandleWrite, this, placeholders::_1, shared_from_this()));

}

void Connection::AsyncReadAll(int len, std::function<void(const boost::system::error_code&, size_t)> handler)
{
	memset(data_, 0, sizeof(data_));
	AsyncRead(0, len, handler);
}

void Connection::AsyncRead(size_t HasRead, size_t len, function<void(const boost::system::error_code&, size_t)> handler)
{
	auto self = shared_from_this();
	socket_.async_read_some(boost::asio::buffer(data_ + HasRead, len - HasRead),
		[=](const boost::system::error_code& ec, size_t  bytesTransfered) {
			//出错
			if (ec)
			{
				handler(ec, HasRead + bytesTransfered);
				return;
			}
			//读取了足够长度的数据
			if (HasRead + bytesTransfered >= len)
			{
				handler(ec, HasRead + bytesTransfered);
				return;
			}
			//长度不足，继续读取
			self->AsyncRead(HasRead + bytesTransfered, len, handler);
		});
}

void Connection::HandleWrite(const boost::system::error_code& error, std::shared_ptr<Connection> shared_self)
{
	try
	{
		if (error)
		{
			cout << "Connection Write Error: " << error.what() << endl;
			close();
			server_->RemoveConnetion(uuid_);
		}
		else
		{
			lock_guard<mutex> lock(mutex_);
			queue_.pop();
			if (!queue_.empty())
			{
				auto node = queue_.front();
				boost::asio::async_write(socket_, boost::asio::buffer(node->data_, node->length_),
					bind(&Connection::HandleWrite, this, placeholders::_1, shared_from_this()));
			}
		}
	}
	catch (exception& e)
	{
		cout << "Connection Write Exception: " << e.what() << endl;
	}
}

LogicNode::LogicNode(std::shared_ptr<Connection> con, std::shared_ptr<ReceiveNode> msg)
	:connection_(con),
	ReceiveNode_(msg)
{
}
