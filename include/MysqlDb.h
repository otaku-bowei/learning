//
// Created by 王柏伟 on 2026/1/18.
//

#ifndef LEARNING_MYSQLDB_H
#define LEARNING_MYSQLDB_H

#include <memory>   // std::unique_ptr
#include <iostream>
#include <odb/mysql/database.hxx>

class MysqlDb {
};

std::shared_ptr<odb::mysql::database> connect();



#endif //LEARNING_MYSQLDB_H