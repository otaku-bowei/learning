//
// Created by hp on 2026/1/8.
//

#ifndef LEARNING_COLLECTIONS_H
#define LEARNING_COLLECTIONS_H
#include <vector>
#include <iostream>
#include <random>
#include <algorithm>
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "AnimalManager.h"
#include <unordered_set>

template <typename T>

class Collections {
};

void testVector();


template <typename T>
void showAllNumbers(const std::vector<T>& nums);

template <typename U>
void showAllAnimal(const std::vector<std::unique_ptr<U>>& animals);
// void showAllAnimal(const std::vector<U*>& animals);

template<typename T, typename KeyFunc>
std::vector<T*> remove_duplicates_keep_order(const std::vector<T*>& items, KeyFunc key_func);

void testMap();

#endif //LEARNING_COLLECTIONS_H