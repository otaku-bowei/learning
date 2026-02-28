//
// Created by 王柏伟 on 2026/1/17.
//

#ifndef LEARNING_USER_H
#define LEARNING_USER_H

#include <string>
#include <odb/core.hxx>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <nlohmann/json.hpp>
#include "JsonSerializer.h"

// #pragma db model version(1,2)
// namespace version1 {
//     #pragma db object table("user")
//     class User {
//         friend class odb::access;
//
//     private:
// #pragma db id not_null column("id")
//         unsigned long long id_{};
// #pragma db not_null column("user_name")
//         std::string username_;
// #pragma db not_null column("password")
//         std::string password_;
// #pragma db not_null column("age")
//         int age_{};
// #pragma db not_null column("birthday") type("DATETIME")
//         boost::posix_time::ptime birthday_{};
// #pragma db not_null column("create_time") type("DATETIME")
//         boost::posix_time::ptime create_time_{};
// #pragma db not_null column("create_user")
//         std::string create_user_;
// #pragma db not_null column("update_time") type("DATETIME")
//         boost::posix_time::ptime update_time_{};
// #pragma db not_null column("update_user")
//         std::string update_user_;
//     };
// }


#pragma db object table("user")
class User {
    friend class odb::access;

private:
#pragma db id not_null column("id")
    unsigned long long id_{};
#pragma db not_null column("user_name")
    std::string username_;
#pragma db not_null column("password")
    std::string password_;
// #pragma db not_null column("name") added(2)
#pragma db not_null column("name")
    std::string name_{};
#pragma db not_null column("age")
    int age_{};
#pragma db not_null column("birthday") type("DATETIME")
    boost::posix_time::ptime birthday_{};
#pragma db not_null column("create_time") type("DATETIME")
    boost::posix_time::ptime create_time_{};
#pragma db not_null column("create_user")
    std::string create_user_;
#pragma db not_null column("update_time") type("DATETIME")
    boost::posix_time::ptime update_time_{};
#pragma db not_null column("update_user")
    std::string update_user_;

public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(User,
        id_, username_, password_, name_, age_,
        birthday_, create_time_, create_user_, update_time_, update_user_)

    User();

    User(unsigned long long id, std::string &username, std::string &password, int age,
         boost::posix_time::ptime birthday, boost::posix_time::ptime create_time,
         std::string &create_user, boost::posix_time::ptime update_time, std::string &update_user);

    [[nodiscard]] std::string getUsername() const;

    [[nodiscard]] int getAge() const;

    [[nodiscard]] boost::posix_time::ptime getBirthday() const;

    [[nodiscard]] unsigned long long getId() const;
};


#endif //LEARNING_USER_H
