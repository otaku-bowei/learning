//
// Created by hp on 2026/1/7.
//
#include "Polymorphism.h"

// 创建两只狗和一只猫

void testPolymorphism() {
    AnimalVector animals;
    const auto dog1 = new Dog("吉娃娃", 1);
    const auto dog2 = new Dog("马犬", 3);
    const auto cat1 = new Cat("王百万", true, 5);
    animals.push_back(dog1);
    animals.push_back(dog2);
    animals.push_back(cat1);

    const auto manager = AnimalManager(animals);
    manager.countOff();
    manager.showLocation();

    cat1->jump();
    dog1->run();

    manager.showLocation();

    cat1->jump();
    dog1->run();
    dog2->run();
    manager.showLocation();

    delete dog1;
    delete dog2;
    delete cat1;
}

