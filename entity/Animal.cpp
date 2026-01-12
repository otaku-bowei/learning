//
// Created by hp on 2026/1/6.
//

#include "Animal.h"

#include <utility>

class Animal {
private:
    mutable int location_ = 0;

protected:
    std::string name_;

public:
    // 构造函数
    explicit Animal(std::string name) : name_(std::move(name)) {
        std::cout << "Animal 构造函数: " << name_ << std::endl;
    }

    // 虚析构函数（虚函数是实现多态的仲要特征）
    virtual ~Animal() {
        std::cout << "Animal 析构函数: " << name_ << std::endl;
    }

    // 虚函数 - C++实现多态的关键，类似Java的抽象方法
    virtual void speak() const {
        std::cout << name_ << " unknow voice" << std::endl;
    }

    void move(const int i) const {
        location_ += i;
    }

    // 普通成员函数
    [[nodiscard]] virtual std::string getName() const {
        return name_;
    }

    // 静态成员
    [[nodiscard]] int getLocation() const {
        return location_;
    }


    //实现 equal 操作
    // 方法1：成员函数形式的 operator==
    bool operator==(const Animal& other) const {
        return name_ == other.name_;
    }

    // 方法2：友元函数形式的 operator==（允许隐式转换）
    friend bool operator==(const Animal& a, const Animal& b) {
        return a.name_ == b.name_;
    }
};
