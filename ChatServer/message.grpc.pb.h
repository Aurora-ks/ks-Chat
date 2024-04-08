// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: message.proto
#ifndef GRPC_message_2eproto__INCLUDED
#define GRPC_message_2eproto__INCLUDED

#include "message.pb.h"

#include <functional>
#include <grpc/impl/codegen/port_platform.h>
#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/client_context.h>
#include <grpcpp/impl/codegen/completion_queue.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace message {

class Varify final {
 public:
  static constexpr char const* service_full_name() {
    return "message.Varify";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status GetVarifyCode(::grpc::ClientContext* context, const ::message::VarifyReq& request, ::message::VarifyRes* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::message::VarifyRes>> AsyncGetVarifyCode(::grpc::ClientContext* context, const ::message::VarifyReq& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::message::VarifyRes>>(AsyncGetVarifyCodeRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::message::VarifyRes>> PrepareAsyncGetVarifyCode(::grpc::ClientContext* context, const ::message::VarifyReq& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::message::VarifyRes>>(PrepareAsyncGetVarifyCodeRaw(context, request, cq));
    }
    class experimental_async_interface {
     public:
      virtual ~experimental_async_interface() {}
      virtual void GetVarifyCode(::grpc::ClientContext* context, const ::message::VarifyReq* request, ::message::VarifyRes* response, std::function<void(::grpc::Status)>) = 0;
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      virtual void GetVarifyCode(::grpc::ClientContext* context, const ::message::VarifyReq* request, ::message::VarifyRes* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      #else
      virtual void GetVarifyCode(::grpc::ClientContext* context, const ::message::VarifyReq* request, ::message::VarifyRes* response, ::grpc::experimental::ClientUnaryReactor* reactor) = 0;
      #endif
    };
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    typedef class experimental_async_interface async_interface;
    #endif
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    async_interface* async() { return experimental_async(); }
    #endif
    virtual class experimental_async_interface* experimental_async() { return nullptr; }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::message::VarifyRes>* AsyncGetVarifyCodeRaw(::grpc::ClientContext* context, const ::message::VarifyReq& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::message::VarifyRes>* PrepareAsyncGetVarifyCodeRaw(::grpc::ClientContext* context, const ::message::VarifyReq& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status GetVarifyCode(::grpc::ClientContext* context, const ::message::VarifyReq& request, ::message::VarifyRes* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::message::VarifyRes>> AsyncGetVarifyCode(::grpc::ClientContext* context, const ::message::VarifyReq& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::message::VarifyRes>>(AsyncGetVarifyCodeRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::message::VarifyRes>> PrepareAsyncGetVarifyCode(::grpc::ClientContext* context, const ::message::VarifyReq& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::message::VarifyRes>>(PrepareAsyncGetVarifyCodeRaw(context, request, cq));
    }
    class experimental_async final :
      public StubInterface::experimental_async_interface {
     public:
      void GetVarifyCode(::grpc::ClientContext* context, const ::message::VarifyReq* request, ::message::VarifyRes* response, std::function<void(::grpc::Status)>) override;
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      void GetVarifyCode(::grpc::ClientContext* context, const ::message::VarifyReq* request, ::message::VarifyRes* response, ::grpc::ClientUnaryReactor* reactor) override;
      #else
      void GetVarifyCode(::grpc::ClientContext* context, const ::message::VarifyReq* request, ::message::VarifyRes* response, ::grpc::experimental::ClientUnaryReactor* reactor) override;
      #endif
     private:
      friend class Stub;
      explicit experimental_async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class experimental_async_interface* experimental_async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class experimental_async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::message::VarifyRes>* AsyncGetVarifyCodeRaw(::grpc::ClientContext* context, const ::message::VarifyReq& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::message::VarifyRes>* PrepareAsyncGetVarifyCodeRaw(::grpc::ClientContext* context, const ::message::VarifyReq& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_GetVarifyCode_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status GetVarifyCode(::grpc::ServerContext* context, const ::message::VarifyReq* request, ::message::VarifyRes* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_GetVarifyCode : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_GetVarifyCode() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_GetVarifyCode() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetVarifyCode(::grpc::ServerContext* /*context*/, const ::message::VarifyReq* /*request*/, ::message::VarifyRes* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestGetVarifyCode(::grpc::ServerContext* context, ::message::VarifyReq* request, ::grpc::ServerAsyncResponseWriter< ::message::VarifyRes>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_GetVarifyCode<Service > AsyncService;
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_GetVarifyCode : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithCallbackMethod_GetVarifyCode() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::message::VarifyReq, ::message::VarifyRes>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context, const ::message::VarifyReq* request, ::message::VarifyRes* response) { return this->GetVarifyCode(context, request, response); }));}
    void SetMessageAllocatorFor_GetVarifyCode(
        ::grpc::experimental::MessageAllocator< ::message::VarifyReq, ::message::VarifyRes>* allocator) {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(0);
    #else
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::experimental().GetHandler(0);
    #endif
      static_cast<::grpc::internal::CallbackUnaryHandler< ::message::VarifyReq, ::message::VarifyRes>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~ExperimentalWithCallbackMethod_GetVarifyCode() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetVarifyCode(::grpc::ServerContext* /*context*/, const ::message::VarifyReq* /*request*/, ::message::VarifyRes* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerUnaryReactor* GetVarifyCode(
      ::grpc::CallbackServerContext* /*context*/, const ::message::VarifyReq* /*request*/, ::message::VarifyRes* /*response*/)
    #else
    virtual ::grpc::experimental::ServerUnaryReactor* GetVarifyCode(
      ::grpc::experimental::CallbackServerContext* /*context*/, const ::message::VarifyReq* /*request*/, ::message::VarifyRes* /*response*/)
    #endif
      { return nullptr; }
  };
  #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
  typedef ExperimentalWithCallbackMethod_GetVarifyCode<Service > CallbackService;
  #endif

  typedef ExperimentalWithCallbackMethod_GetVarifyCode<Service > ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_GetVarifyCode : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_GetVarifyCode() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_GetVarifyCode() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetVarifyCode(::grpc::ServerContext* /*context*/, const ::message::VarifyReq* /*request*/, ::message::VarifyRes* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_GetVarifyCode : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_GetVarifyCode() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_GetVarifyCode() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetVarifyCode(::grpc::ServerContext* /*context*/, const ::message::VarifyReq* /*request*/, ::message::VarifyRes* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestGetVarifyCode(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_GetVarifyCode : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithRawCallbackMethod_GetVarifyCode() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodRawCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->GetVarifyCode(context, request, response); }));
    }
    ~ExperimentalWithRawCallbackMethod_GetVarifyCode() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetVarifyCode(::grpc::ServerContext* /*context*/, const ::message::VarifyReq* /*request*/, ::message::VarifyRes* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerUnaryReactor* GetVarifyCode(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)
    #else
    virtual ::grpc::experimental::ServerUnaryReactor* GetVarifyCode(
      ::grpc::experimental::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)
    #endif
      { return nullptr; }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_GetVarifyCode : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_GetVarifyCode() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler<
          ::message::VarifyReq, ::message::VarifyRes>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::message::VarifyReq, ::message::VarifyRes>* streamer) {
                       return this->StreamedGetVarifyCode(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_GetVarifyCode() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status GetVarifyCode(::grpc::ServerContext* /*context*/, const ::message::VarifyReq* /*request*/, ::message::VarifyRes* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedGetVarifyCode(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::message::VarifyReq,::message::VarifyRes>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_GetVarifyCode<Service > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_GetVarifyCode<Service > StreamedService;
};

}  // namespace message


#endif  // GRPC_message_2eproto__INCLUDED
