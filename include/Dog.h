//
// Created by hp on 2026/1/6.
//

#ifndef LEARNING_DOG_H
#define LEARNING_DOG_H
#include <string>
#include <iostream>
#include "Animal.h"


class Dog : public Animal {

private:
    int work_way_;

    void beingFaster() {
        work_way_++;
    }

public:
    explicit Dog(const std::string& name, int workWay);

    // 虚函数 - C++实现多态的关键，类似Java的抽象方法
    void speak() const override;

    void run();

    // 继承的成员函数
    [[nodiscard]] std::string getName() const override ;

};

#endif //LEARNING_ANIMAL_H