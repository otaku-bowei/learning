//
// Created by 王柏伟 on 2026/1/17.
//

#include "../../include/User.h"

User::User() = default;

User::User(long id, std::string &username, std::string &password, int age, unsigned long long birthday, unsigned long long create_time, std::string &create_user, unsigned long long update_time, std::string &update_user) : id_(id),
                                                                                                                                                                                          username_(username), password_(password), age_(age), birthday_(birthday), create_time_(create_time),
                                                                                                                                                                                          create_user_(create_user), update_time_(update_time), update_user_(update_user) {
}

std::string User::getUsername() const {
    return username_;
}

int User::getAge() const{
    return age_;
}

unsigned long long User::getBirthday() const {
    return birthday_;
}

long User::getId() const {
    return id_;
}
