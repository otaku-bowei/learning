//
// Created by 王柏伟 on 2026/1/15.
//

#ifndef LEARNING_CATFAMILY_H
#define LEARNING_CATFAMILY_H
#include <string>

#include "Animal.h"


class CatFamily : public Animal {

public:
    explicit CatFamily(const std::string &name);

    ~CatFamily() override;

    const bool belong(const std::string &name) override;
};





#endif //LEARNING_CATFAMILY_H