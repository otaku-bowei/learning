//
// Created by hp on 2026/2/24.
//

#include "../../include/UserController.h"
#include <drogon/HttpResponse.h>
#include <drogon/utils/Utilities.h>

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
    Json::Value ret;
    ret["code"] = 0;
    ret["message"] = "success";

    Json::Value users;
    for (int i = 1; i <= 3; i++) {
        Json::Value user;
        user["id"] = i;
        user["name"] = "用户" + std::to_string(i);
        user["email"] = "user" + std::to_string(i) + "@example.com";
        users.append(user);
    }
    ret["data"] = users;

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
