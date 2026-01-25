//
// Created by 王柏伟 on 2026/1/17.
//

#ifndef LEARNING_USER_H
#define LEARNING_USER_H

#include <string>
#include <odb/core.hxx>
#include <boost/date_time/posix_time/posix_time.hpp>


#pragma db object
class SimpleUser {
    friend class odb::access;

private:
#pragma db id not_null column("id")
    unsigned long long id_{};
#pragma db not_null column("user_name")
    std::string username_;
#pragma db not_null column("password")
    std::string password_;
#pragma db not_null column("age")
    int age_{};


#pragma db not_null column("update_user")
    std::string update_user_;

public:
    SimpleUser();
    SimpleUser(unsigned long long id, std::string &username, std::string &password, int age);

    [[nodiscard]] std::string getUsername() const;

    [[nodiscard]] int getAge() const;

    [[nodiscard]] unsigned long long getId() const;
};


#endif //LEARNING_USER_H
