//
// Created by hp on 2026/2/12.
//

#include "../../include/gRPC.h"

GRPC::GRPC() = default;
GRPC::~GRPC() = default;

// 获取用户信息
Status GRPC::getUser(ServerContext* context,
               const user_service::UserRequest* request,
               user_service::UserResponse* response) {
    std::cout << "收到请求，用户ID: " << request->id() << std::endl;

    // 模拟查询数据库
    response->set_code(200);
    response->set_message("success");

    user_service::User* user = response->mutable_user();
    user->set_name("张三");
    user->set_email("zhangsan@example.com");
    user->set_age(28);

    return Status::OK;
}

Status GRPC::createUser(ServerContext *context,
                              const user_service::User *request,
                              user_service::UserResponse *response) {

    std::cout << "创建用户: " << request->name() << std::endl;

    response->set_code(201);
    response->set_message("User created successfully");

    // 模拟设置返回的用户ID
    response->mutable_user()->CopyFrom(*request);
    return Status::OK;
}