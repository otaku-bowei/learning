//
// Created by 王柏伟 on 2026/1/15.
//

#include "DogFamily.h"


DogFamily::DogFamily(const std::string &name) : Animal(name) {
}

DogFamily::~DogFamily() = default;

const bool DogFamily::belong(const std::string &name) {
    return name.find("dog");
}