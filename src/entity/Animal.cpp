//
// Created by hp on 2026/1/6.
//

#include "../include/Animal.h"

Animal::Animal(std::string name) : name_(std::move(name)) {
    std::cout << "Animal 构造函数: " << name_ << std::endl;
}


// 虚析构函数（虚函数是实现多态的仲要特征）
Animal::~Animal() {
    std::cout << "Animal 析构函数: " << name_ << std::endl;
}

// 虚函数 - C++实现多态的关键，类似Java的抽象方法
void Animal::speak() const {
    std::cout << name_ << " unknow voice" << std::endl;
}

void Animal::move(const int i) const {
    location_ += i;
}


// 普通成员函数
[[nodiscard]] std::string Animal::getName() const {
    return name_;
}

// 静态成员
[[nodiscard]] int Animal::getLocation() const {
    return location_;
}


//实现 equal 操作
// 方法1：成员函数形式的 operator==
bool Animal::operator==(const Animal &other) const {
    return name_ == other.name_;
}

bool Animal::operator<(const Animal &other) const {
    return name_ < other.name_;
}

bool Animal::equal(const Animal* other) const {
    return getName() == other->getName();
};

bool operator==(const Animal &a, const Animal &b) {
    return a.name_ == b.name_;
}


const bool Animal::belong(const std::string &name) {
    return false;
}
