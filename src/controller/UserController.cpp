//
// Created by hp on 2026/2/24.
//

#include "../../include/UserController.h"
#include <drogon/HttpResponse.h>
#include <drogon/utils/Utilities.h>

#include "Drogon.h"

UserController::UserController() = default;
UserController::UserController(const UserDao &userDao) : userDao_(userDao){};
void UserController::getUser(const HttpRequestPtr& req,
                             std::function<void(const HttpResponsePtr&)>&& callback,
                             int userId) {
    Json::Value ret;
    ret["code"] = 0;
    ret["message"] = "success";
    ret["data"]["id"] = userId;
    ret["data"]["name"] = "张三";
    ret["data"]["email"] = "zhangsan@example.com";

    auto resp = HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}

void UserController::getAllUsers(const HttpRequestPtr& req,
                                  std::function<void(const HttpResponsePtr&)>&& callback) {
    auto users = userDao_.queryUsers("default");

    Json::Value ret;
    ret["code"] = 0;
    ret["message"] = "success";

    Json::Value usersJson;
    for (int i = 1; i <= 3; i++) {
        Json::Value user;
        user["id"] = i;
        user["name"] = "用户" + std::to_string(i);
        user["email"] = "user" + std::to_string(i) + "@example.com";
        usersJson.append(user);
    }
    ret["data"] = usersJson;

    auto resp = HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}

void UserController::createUser(const HttpRequestPtr& req,
                                  std::function<void(const HttpResponsePtr&)>&& callback) {
    auto json = req->getJsonObject();

    Json::Value ret;
    ret["code"] = 0;
    ret["message"] = "用户创建成功";
    ret["data"]["id"] = 100;

    auto resp = HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}

void UserController::updateUser(const HttpRequestPtr& req,
                                std::function<void(const HttpResponsePtr&)>&& callback,
                                int userId) {
    Json::Value ret;
    ret["code"] = 0;
    ret["message"] = "用户更新成功";
    ret["data"]["id"] = userId;

    auto resp = HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}

void UserController::deleteUser(const HttpRequestPtr& req,
                                std::function<void(const HttpResponsePtr&)>&& callback,
                                int userId) {
    Json::Value ret;
    ret["code"] = 0;
    ret["message"] = "用户删除成功";

    auto resp = HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}

void UserController::testInjection() {
    kgr::container container;

    container.invoke([](UserController &ctrl) {
        std::cout << "=== UserController 注入测试 ===" << std::endl;
        std::cout << "UserController 地址: " << &ctrl << std::endl;
        std::cout << "UserDao 成员地址: " << &ctrl.userDao_ << std::endl;
    });

    // auto &userDaoFromContainer = container.service<UserDao>();
    // std::cout << "Container 中 UserDao 地址: " << &userDaoFromContainer << std::endl;

    container.invoke([](UserController &ctrl, UserDao &dao) {
        std::cout << "=== 验证是否为同一对象 ===" << std::endl;
        std::cout << "传入的 UserDao 地址: " << &dao << std::endl;
        std::cout << "Controller 内的 UserDao 地址: " << &ctrl.userDao_ << std::endl;

        if (&dao == &ctrl.userDao_) {
            std::cout << "✅ 是同一个对象！注入成功" << std::endl;
        } else {
            std::cout << "❌ 不是同一个对象" << std::endl;
        }
    });
}

