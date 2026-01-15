//
// Created by hp on 2026/1/6.
//

#ifndef LEARNING_DOG_H
#define LEARNING_DOG_H
#include <string>
#include <iostream>
#include "Animal.h"
#include "DogFamily.h"
#include "TrainAnimal.h"


class Dog : public DogFamily , public TrainAnimal{

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

    const void makeAnimalSayOtherThings(const std::string &sentence) override;

    const bool belong(const std::string &name) override;

};

#endif //LEARNING_ANIMAL_H