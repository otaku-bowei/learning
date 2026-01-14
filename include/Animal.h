//
// Created by hp on 2026/1/6.
//

#ifndef LEARNING_ANIMAL_H
#define LEARNING_ANIMAL_H
#include <string>
#include <iostream>
#include <utility>

class Animal {
private:
    mutable int location_ = 0;

protected:
    std::string name_;

public:
    // 构造函数
    explicit Animal(std::string name);

    // 虚析构函数（虚函数是实现多态的仲要特征）
    virtual ~Animal();

    // 虚函数 - C++实现多态的关键，类似Java的抽象方法
    virtual void speak() const;

    void move(int i) const;

    // 普通成员函数
    [[nodiscard]] virtual std::string getName() const;

    // 静态成员
    [[nodiscard]] int getLocation() const;

    //实现 equal 操作
    // 方法1：成员函数形式的 operator==
    bool operator==(const Animal& other) const;

    bool operator<(const Animal& other) const;

    bool equal(const Animal* other) const;

    // 方法2：友元函数形式的 operator==（允许隐式转换）
    friend bool operator==(const Animal& a, const Animal& b);
};


#endif //LEARNING_ANIMAL_H