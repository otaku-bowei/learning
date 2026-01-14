//
// Created by 王柏伟 on 2026/1/14.
//

#ifndef LEARNING_TRAINANIMAL_H
#define LEARNING_TRAINANIMAL_H
#include "Animal.h"


class TrainAnimal {

public:
    TrainAnimal();

    virtual ~TrainAnimal();

    virtual const void makeAnimalSayOtherThings(const std::string &sentence);
};


#endif //LEARNING_TRAINANIMAL_H
