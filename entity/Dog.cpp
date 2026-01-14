//
// Created by hp on 2026/1/6.
//

#include "../include/Dog.h"



Dog::Dog(const std::string& name, const int workWay) : Animal(name), work_way_(workWay) {
}

// 虚函数 - C++实现多态的关键，类似Java的抽象方法
void Dog::speak() const {
    std::cout << name_ << "wol wol" << std::endl;
}

void Dog::run() {
    move(work_way_);
    beingFaster();
}

// 继承的成员函数
[[nodiscard]] std::string Dog::getName() const {
    return name_;
}
