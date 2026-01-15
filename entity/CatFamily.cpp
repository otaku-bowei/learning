//
// Created by 王柏伟 on 2026/1/15.
//

#include "../include/CatFamily.h"

CatFamily::CatFamily(const std::string &name) : Animal(name) {
}

CatFamily::~CatFamily() = default;

const bool CatFamily::belong(const std::string &name) {
    return name.find("cat");
}
