//
// Created by hp on 2026/1/8.
//

#ifndef LEARNING_COLLECTIONS_H
#define LEARNING_COLLECTIONS_H
#include <vector>
#include <iostream>
#include <random>
#include <algorithm>
#include "../entity/Animal.h"
#include "../entity/Dog.h"
#include "../entity/Cat.h"


template <typename T>

class Collections {
};

void testVector();


template <typename T>
void showAllNumbers(const std::vector<T>& nums);

void testMap();

#endif //LEARNING_COLLECTIONS_H