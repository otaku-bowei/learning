//
// Created by hp on 2026/1/6.
//

#include "Cat.h"

class Cat : public Animal {

private:
    bool play_way_;
    int work_way_;

public:
    explicit Cat(const std::string& name, const bool playWay, const int workWay) : Animal(name), play_way_(playWay), work_way_(workWay) {
    }

    // 虚函数 - C++实现多态的关键，类似Java的抽象方法
    void speak() const override {
        std::cout << name_ << "meow meow" << std::endl;
    }

    void jump() {
        if (play_way_) {
            move(work_way_);
        }
        changePlay();
    }

    // 继承的成员函数
    [[nodiscard]] std::string getName() const override {
        return name_;
    }

    // 自有的成员函数
    [[nodiscard]] bool showWorkWay() const {
        return play_way_;
    }

    void changePlay() {
        play_way_ = !play_way_;
    }

};