//
// Created by hp on 2026/1/6.
//

#include "Dog.h"

class Dog : public Animal {

private:
    int work_way_;

    void beingFaster() {
        work_way_++;
    }

public:
    explicit Dog(const std::string& name, const int workWay) : Animal(name), work_way_(workWay) {
    }

    // 虚函数 - C++实现多态的关键，类似Java的抽象方法
    void speak() const override {
        std::cout << name_ << "wol wol" << std::endl;
    }

    void run() {
        Animal::move(work_way_);
        beingFaster();
    }

    // 继承的成员函数
    [[nodiscard]] std::string getName() const override {
        return name_;
    }

};