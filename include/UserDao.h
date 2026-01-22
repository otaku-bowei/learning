//
// Created by 王柏伟 on 2026/1/18.
//

#ifndef LEARNING_USERDAO_H
#define LEARNING_USERDAO_H
#include <memory>   // std::unique_ptr
#include <iostream>
#include <odb/mysql/database.hxx>
#include "MysqlDb.h"
// #include "User.h"
#include "User-odb.hxx"

class UserDao {
};

//CURD
void insertBatchUser(std::vector<std::unique_ptr<User>> &entities, int batch_size);

void doSomething(const std::string &sql);

#endif //LEARNING_USERDAO_H