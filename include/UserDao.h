//
// Created by 王柏伟 on 2026/1/18.
//

#ifndef LEARNING_USERDAO_H
#define LEARNING_USERDAO_H
#include <memory>   // std::unique_ptr
#include <iostream>
#include <odb/mysql/database.hxx>
#include "MysqlDb.h"
#include "User.h"

class UserDao {
};

//CURD
void insertBatchUser(std::vector<std::unique_ptr<User>> &entities, int batch_size);

#endif //LEARNING_USERDAO_H