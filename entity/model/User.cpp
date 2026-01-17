//
// Created by 王柏伟 on 2026/1/17.
//

#include "../../include/User.h"


User::User(const std::string &username, std::string &password, int age, time_t birthday, time_t create_time, std::string &create_user, time_t update_time, std::string &update_user) :
username_(username), password_(password), age_(age), birthday_(birthday), create_time_(create_time), create_user_(create_user), update_time_(update_time), update_user_(update_user){
}

std::string User::getUsername() const {
    return username_;
}

int User::getAge() const{
    return age_;
}

time_t User::getBirthday() const {
    return birthday_;
}
