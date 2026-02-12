//
// Created by hp on 2026/1/7.
//

#include "../include/AnimalManager.h"


AnimalManager::AnimalManager(std::vector<std::unique_ptr<Animal> > &manageAnimals) : animals(std::move(manageAnimals)) {
// AnimalManager::AnimalManager(const std::vector<Animal*> &manageAnimals) : animals(manageAnimals) {
};

AnimalManager::AnimalManager() = default ;

// void countOff() const {
void AnimalManager::countOff() const {
    // for (const Animal* animal: animals) {
    // for (const Animal animal: animals) {
    for (const auto &animal: animals) {
        animal->speak();
        // animal.speak();
    }
}

void AnimalManager::showLocation() const {
    // for (const Animal* animal: animals) {
    // for (const Animal animal: animals) {
    for (const auto &animal: animals) {
        std::cout << animal->getName() <<"的位置是:" << animal->getLocation() << std::endl;
        // std::cout << animal.getName() << "的位置是:" << animal.getLocation() << std::endl;
    }
}

void AnimalManager::joinCat(const std::string &name) {
    // const auto cat = std::make_unique<Cat>(name,  true, 5);
    animals.push_back(std::make_unique<Cat>(name,  true, 5));
};

void AnimalManager::joinDog(const std::string &name) {
    // const auto dog = std::make_unique<Dog>(name, 5);
    animals.push_back(std::make_unique<Dog>(name, 5));
}

void AnimalManager::showBelong() {
    for (const auto &animal: animals) {
        if (animal -> belong(animal -> getName())) {
            animal -> speak();
        }
    }
}
