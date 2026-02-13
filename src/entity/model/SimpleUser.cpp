//
// Created by 王柏伟 on 2026/1/17.
//

#include "../../../include/SimpleUser.h"

SimpleUser::SimpleUser() = default;

SimpleUser::SimpleUser(unsigned long long id, const std::string &username, const std::string &password, int age) : id_(id), username_(username), password_(password), age_(age) {
}

std::string SimpleUser::getUsername() const {
    return username_;
}

int SimpleUser::getAge() const{
    return age_;
}

unsigned long long SimpleUser::getId() const {
    return id_;
}
