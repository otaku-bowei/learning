//
// Created by hp on 2026/2/27.
//

#ifndef LEARNING_INIT_H
#define LEARNING_INIT_H

#include <iostream>
#include <drogon/drogon.h>
using namespace drogon;

class Init {
};

void initLogger();
void initKangaru();
void initSqlPool();
void initController();

#endif //LEARNING_INIT_H