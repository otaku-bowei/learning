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
private:
    const std::string username_;
    std::string password_;
    int age_;
    time_t birthday_;
    const time_t create_time_;
    std::string create_user_;
    time_t update_time_;
    std::string update_user_;

public:
    User(const std::string &username, std::string &password, int age, time_t birthday, time_t create_time, std::string &create_user, time_t update_time, std::string &update_user);

    [[nodiscard]] std::string getUsername() const;
    [[nodiscard]] int getAge() const;
    [[nodiscard]] time_t getBirthday() const;
};


#endif //LEARNING_USER_H