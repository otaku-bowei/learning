//
// Created by hp on 2026/1/7.
//

#include "AnimalManager.h"


class AnimalManager {
    //使用指针对象，对传入的内存地址操作，修改对应的值时容器外的对象也会变更，使用值语义有副本操作，不会对容器外对象有影响
private:
    // std::vector<Animal*> animals;
    // std::vector<Animal> animals;
    std::vector<std::unique_ptr<Animal> > animals;

public:
    // explicit AnimalManager(const std::vector<Animal*> &manageAnimals) : animals(manageAnimals) {
    // explicit AnimalManager(const std::vector<Animal> &manageAnimals) : animals(manageAnimals) {
    explicit AnimalManager(std::vector<std::unique_ptr<Animal> > &manageAnimals) : animals(std::move(manageAnimals)) {
    };

    // void countOff() const {
    void countOff() const {
        // for (const Animal* animal: animals) {
        // for (const Animal animal: animals) {
        for (const auto &animal: animals) {
            animal->speak();
            // animal.speak();
        }
    }

    void showLocation() const {
        // for (const Animal* animal: animals) {
        // for (const Animal animal: animals) {
        for (const auto &animal: animals) {
            std::cout << animal->getName() <<"的位置是:" << animal->getLocation() << std::endl;
            // std::cout << animal.getName() << "的位置是:" << animal.getLocation() << std::endl;
        }
    }
};
