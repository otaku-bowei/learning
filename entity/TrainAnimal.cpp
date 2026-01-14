//
// Created by 王柏伟 on 2026/1/14.
//

#include "../include/TrainAnimal.h"


TrainAnimal::TrainAnimal() = default;

TrainAnimal::~TrainAnimal() = default;

const void TrainAnimal::makeAnimalSayOtherThings(const std::string &sentence) {
    std::cout << " says:  " << sentence << std::endl;
}

