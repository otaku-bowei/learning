//
// Created by hp on 2026/1/7.
//

#include "Polymorphism.h"

// 创建两只狗和一只猫

void testPolymorphism() {
    AnimalVector animals;
    const auto dog1 = Dog("吉娃娃", 1);
    const auto dog2 = Dog("马犬", 3);
    const auto cat1 = Cat("王百万", true, 5);
    animals.push_back(dog1);

    auto manager = AnimalManager(animals);
}

