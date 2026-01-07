//
// Created by hp on 2026/1/7.
//

#include "AnimalManager.h"



class AnimalManager {
    //使用指针对象，对传入的内存地址操作，修改对应的值时容器外的对象也会变更，使用值语义有副本操作，不会对容器外对象有影响
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
