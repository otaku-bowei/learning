//
// Created by 王柏伟 on 2026/1/15.
//

#ifndef LEARNING_DOGFAMILY_H
#define LEARNING_DOGFAMILY_H
#include <string>

#include "Animal.h"

class DogFamily : public Animal {

public:
    explicit DogFamily(const std::string &name);

    ~DogFamily() override;

    const bool belong(const std::string &name) override;
};

#endif //LEARNING_DOGFAMILY_H