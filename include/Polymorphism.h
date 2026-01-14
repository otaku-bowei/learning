//
// Created by hp on 2026/1/7.
//

#ifndef LEARNING_POLYMORPHISM_H
#define LEARNING_POLYMORPHISM_H
#include "AnimalManager.h"
#include <memory>
#include <vector>

// 此处关注是否使用 指针的区别
using AnimalVector = std::vector<Animal*>;
// using AnimalVector = std::vector<Animal>;
// using AnimalVector = std::vector<std::unique_ptr<Animal>>;

void testPolymorphism();

#endif //LEARNING_POLYMORPHISM_H