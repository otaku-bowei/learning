//
// Created by hp on 2026/1/7.
//

#include "../include/AnimalManager.h"


// AnimalManager::AnimalManager(std::vector<std::unique_ptr<Animal> > &manageAnimals) : animals(std::move(manageAnimals)) {
AnimalManager::AnimalManager(const std::vector<Animal*> &manageAnimals) : animals(manageAnimals) {
};

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
