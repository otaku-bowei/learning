//
// Created by hp on 2026/2/24.
//

#ifndef LEARNING_USERCONTROLLER_H
#define LEARNING_USERCONTROLLER_H


#include <drogon/HttpController.h>
#include <drogon/HttpResponse.h>
#include <json/json.h>
using namespace drogon;

class UserController : public HttpController<UserController> {
public:
    METHOD_LIST_BEGIN
    ADD_METHOD_TO(UserController::getUser, "/user/{1}", Get);
    ADD_METHOD_TO(UserController::getAllUsers, "/users", Get);
    ADD_METHOD_TO(UserController::createUser, "/user", Post);
    ADD_METHOD_TO(UserController::updateUser, "/user/{1}", Put);
    ADD_METHOD_TO(UserController::deleteUser, "/user/{1}", Delete);
    METHOD_LIST_END

    void getUser(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& callback, int userId);
    void getAllUsers(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& callback);
    void createUser(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& callback);
    void updateUser(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& callback, int userId);
    void deleteUser(const HttpRequestPtr& req, std::function<void(const HttpResponsePtr&)>&& callback, int userId);
};


#endif //LEARNING_USERCONTROLLER_H