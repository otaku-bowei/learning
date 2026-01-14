//
// Created by hp on 2026/1/7.
//

#ifndef LEARNING_ANIMALMANAGER_H
#define LEARNING_ANIMALMANAGER_H
#include <iostream>
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include <memory>
#include <vector>


class AnimalManager {
    //使用指针对象，对传入的内存地址操作，修改对应的值时容器外的对象也会变更，使用值语义有副本操作，不会对容器外对象有影响
private:
    std::vector<Animal*> animals;
    // std::vector<Animal> animals;
    // std::vector<std::unique_ptr<Animal> > animals;

public:
    explicit AnimalManager(const std::vector<Animal*> &manageAnimals);
    // explicit AnimalManager(const std::vector<Animal> &manageAnimals);
    // explicit AnimalManager(std::vector<std::unique_ptr<Animal> > &manageAnimals) ;


    // void countOff() const {
    void countOff() const;

    void showLocation() const;
};

#endif //LEARNING_ANIMALMANAGER_H