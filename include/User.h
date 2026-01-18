//
// Created by 王柏伟 on 2026/1/17.
//

#ifndef LEARNING_USER_H
#define LEARNING_USER_H

#include <string>
#include <odb/core.hxx>
#include <ctime>


#pragma db object
class User {
    friend class odb::access;

private:
#pragma db id not_null column("id")
    long id_;
#pragma db not_null column("user_name")
    std::string username_;
#pragma db not_null column("password")
    std::string password_;
#pragma db not_null column("age")
    int age_;
#pragma db not_null column("birthday") type("DATETIME")
    time_t birthday_;
#pragma db not_null column("create_time") type("DATETIME")
    time_t create_time_;
#pragma db not_null column("create_user")
    std::string create_user_;
#pragma db not_null column("update_time") type("DATETIME")
    time_t update_time_;
#pragma db not_null column("update_user")
    std::string update_user_;

public:
    User(long id, std::string &username, std::string &password, int age, time_t birthday, time_t create_time,
         std::string &create_user, time_t update_time, std::string &update_user);

    [[nodiscard]] std::string getUsername() const;

    [[nodiscard]] int getAge() const;

    [[nodiscard]] time_t getBirthday() const;

    [[nodiscard]] long getId() const;
};


#endif //LEARNING_USER_H
