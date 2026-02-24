// //
// // Created by hp on 2026/2/12.
// //
//
// #ifndef LEARNING_GRPC_H
// #define LEARNING_GRPC_H
// #include <grpcpp/grpcpp.h>
// #include "../src/service/grpc/UserService.grpc.pb.h"
// #include "../src/service/UserService.pb.h"
//
// namespace user_service {
//     class User;
//     class UserResponse;
//     class UserRequest;
// }
//
// using grpc::Server;
// using grpc::ServerBuilder;
// using grpc::ServerContext;
// using grpc::Status;
//
// class GRPC final : public user_service::UserService::Service {
// public:
//     GRPC();
//     ~GRPC() override;
//
//     // 获取用户信息
//     Status getUser(ServerContext* context,
//                    const user_service::UserRequest* request,
//                    user_service::UserResponse* response);
//
//     // 创建用户
//     Status createUser(ServerContext* context,
//                      const user_service::User* request,
//                      user_service::UserResponse* response);
//
// };
//
// // 启动 gRPC 服务器
// inline void RunServer() {
//     std::string server_address("0.0.0.0:50051");
//     GRPC service;
//
//     ServerBuilder builder;
//     builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
//     builder.RegisterService(&service);
//
//     std::unique_ptr<Server> server(builder.BuildAndStart());
//     std::cout << "gRPC 服务器启动，监听: " << server_address << std::endl;
//
//     server->Wait();
// }
//
//
// #endif //LEARNING_GRPC_H