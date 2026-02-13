//
// Created by 王柏伟 on 2026/1/18.
//

#ifndef LEARNING_USERDAO_H
#define LEARNING_USERDAO_H
#include <memory>   // std::unique_ptr
#include <iostream>
#include "ConnectionGuard.h"
// #include "../entity/model/User-odb.hxx"
#include "../src/entity/model/SimpleUser-odb.hxx"
#include "ConnectionSingleton.h"

class UserDao {
};

//CURD
// void insertBatchUser(std::vector<std::unique_ptr<User>> &entities, int batch_size);
void insertBatchUser(std::vector<std::unique_ptr<SimpleUser>> &entities, int batch_size);


#endif //LEARNING_USERDAO_H