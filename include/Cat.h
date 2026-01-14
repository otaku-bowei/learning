//
// Created by hp on 2026/1/6.
//

#ifndef LEARNING_CAT_H
#define LEARNING_CAT_H
#include <string>
#include <iostream>

#include "Animal.h"


class Cat : public Animal {

private:
    bool play_way_;
    int work_way_;

public:
    explicit Cat(const std::string& name, const bool playWay, const int workWay);

    // 虚函数 - C++实现多态的关键，类似Java的抽象方法
    void speak() const override;

    void jump();

    // 继承的成员函数
    [[nodiscard]] std::string getName() const override;

    // 自有的成员函数
    [[nodiscard]] bool showWorkWay() const ;

    void changePlay();

};

#endif //LEARNING_ANIMAL_H