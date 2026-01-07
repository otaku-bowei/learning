//
// Created by hp on 2026/1/7.
//

#ifndef LEARNING_POLYMORPHISM_H
#define LEARNING_POLYMORPHISM_H
#include "../entity/AnimalManager.cpp"
#include <memory>
#include <vector>

// 此处关注是否使用 指针的区别
// using AnimalVector = std::vector<Animal*>;
using AnimalVector = std::vector<Animal>;

void testPolymorphism();

#endif //LEARNING_POLYMORPHISM_H