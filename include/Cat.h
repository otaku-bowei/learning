//
// Created by hp on 2026/1/6.
//

#ifndef LEARNING_CAT_H
#define LEARNING_CAT_H
#include <string>
#include <iostream>

#include "Animal.h"
#include "CatFamily.h"
#include "Dog.h"
#include "TrainAnimal.h"


class Cat : public CatFamily, public TrainAnimal {

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

    const void makeAnimalSayOtherThings(const std::string &sentence) override;

    const bool belong(const std::string &name) override;

};

#endif //LEARNING_ANIMAL_H