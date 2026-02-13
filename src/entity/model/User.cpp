//
// Created by 王柏伟 on 2026/1/17.
//

#include "../include/User.h"

User::User() = default;

User::User(unsigned long long id, std::string &username, std::string &password, int age, boost::posix_time::ptime birthday, boost::posix_time::ptime create_time, std::string &create_user, boost::posix_time::ptime update_time, std::string &update_user) : id_(id),
                                                                                                                                                                                          username_(username), password_(password), age_(age), birthday_(birthday), create_time_(create_time),
                                                                                                                                                                                          create_user_(create_user), update_time_(update_time), update_user_(update_user) {
}

std::string User::getUsername() const {
    return username_;
}

int User::getAge() const{
    return age_;
}

boost::posix_time::ptime User::getBirthday() const {
    return birthday_;
}

unsigned long long User::getId() const {
    return id_;
}
