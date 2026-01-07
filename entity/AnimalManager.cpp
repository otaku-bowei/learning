//
// Created by hp on 2026/1/7.
//

#include "AnimalManager.h"



class AnimalManager {
private:
    std::vector<Animal*> animals;

public:
    explicit AnimalManager(const std::vector<Animal*>& manageAnimals) : animals(manageAnimals) {
    };

    void countOff() const {
        for (const Animal* animal: animals) {
            animal->speak();
        }
    }

    void showLocation() const {
        for (const Animal* animal: animals) {
            std::cout << animal->getName() <<"的位置是:" << animal->getLocation() << std::endl;
        }
    }
};
