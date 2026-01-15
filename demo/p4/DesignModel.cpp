//
// Created by 王柏伟 on 2026/1/15.
//

#include "../../include/DesignModel.h"

#include "AnimalManager.h"


void workerFind() {

    //1.在猫科和狗科中找出猫
    const auto cat = std::make_unique<Cat>("王百万",  true, 5);
    const auto dog = std::make_unique<Dog>("小丁", 5);
    const auto mouse = std::make_unique<Cat>("丁百万",  true, 5);
    const auto turtle = std::make_unique<Dog>("小王", 5);

    std::vector<Animal*> animals;
    animals.push_back(dog.get());
    animals.push_back(cat.get());
    animals.push_back(mouse.get());
    animals.push_back(turtle.get());

    for (auto & animal : animals) {
        if (animal -> belong(animal -> getName())) {
            animal -> speak();
        }
    }
}

void factory() {
    std::vector<std::unique_ptr<Animal>> animals;
    const auto manager = std::make_unique<AnimalManager>(animals);
    manager -> joinCat("王百万");
    manager -> joinCat("丁百万");
    manager -> joinDog("小王");

    manager -> showBelong();


}

