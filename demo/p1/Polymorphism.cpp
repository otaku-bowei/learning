//
// Created by hp on 2026/1/7.
//
#include "../../include/Polymorphism.h"

// 创建两只狗和一只猫

void testPolymorphism() {
    AnimalVector animals;
    // const auto dog1 = new Dog("吉娃娃", 1);
    // const auto dog2 = new Dog("马犬", 3);
    // const auto cat1 = new Cat("王百万", true, 5);
    auto dog1 = std::make_unique<Dog>("吉娃娃", 1);
    auto dog2 = std::make_unique<Dog>("马犬", 3);
    auto cat1 = std::make_unique<Cat>("王百万", true, 5);
    // animals.push_back(dog1.get());
    // animals.push_back(dog2.get());
    // animals.push_back(cat1.get());

    // &&可以引用指针的地址
    // auto &&cat2 = std::move(cat1);
    // 指向该指针
    // auto cat2 = *std::move(cat1);
    //move 操作会将指针完全转移到另一个变量
    // auto cat2 = std::move(cat1);
    // auto cat2 = cat1.get();
    // auto cat2(std::move(cat1));
    // cat2->jump();
    cat1->jump();
    // cat2->jump();

    animals.push_back(std::move(dog1));
    animals.push_back(std::move(dog2));
    animals.push_back(std::move(cat1));

    const auto manager = AnimalManager(animals);
    manager.countOff();
    manager.showLocation();

    //使用智能指针时这里为null--unique_ptr的设计理念
    // cat1->jump();
    // dog1->run();
    // cat1.jump();
    // dog1.run();

    manager.showLocation();

    // cat1->jump();
    dog1->run();
    dog2->run();
    // cat1.jump();
    // dog1.run();
    // dog2.run();
    manager.showLocation();

    //使用指针的话AnimalManager外的对象能看到会受影响
    std::cout << "训练结束" << std::endl;
    std::cout << cat1->getName() << "的位置是" << cat1->getLocation() << std::endl;
    // std::cout << cat1.getName() << "的位置是" << cat1.getLocation() << std::endl;

    // delete dog1;
    // delete dog2;
    // delete cat1;
}

