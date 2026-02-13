//
// Created by defsoul on 2026/1/26.
//

#ifndef LEARNING_MYSQLPOOL_H
#define LEARNING_MYSQLPOOL_H


#include <odb/mysql/database.hxx>
#include <queue>
#include <memory>
#include <mutex>
#include <condition_variable>
#include <iostream>

class MysqlPool {
private:
    std::queue<std::shared_ptr<odb::mysql::database>> pool_;
    std::mutex mutex_;
    std::condition_variable cond_;
    size_t max_pool_size_;
    size_t current_size_;

    // 连接参数
    std::string user_;
    std::string password_;
    std::string database_;
    std::string host_;
    std::string socket_;
    unsigned int port_;

public:
    explicit MysqlPool(size_t max_pool_size = 10);

    std::shared_ptr<odb::mysql::database> getConnection();

    void releaseConnection(std::shared_ptr<odb::mysql::database> conn);

private:
    std::shared_ptr<odb::mysql::database> createConnection();

    bool testConnection(std::shared_ptr<odb::mysql::database> conn);
};



#endif //LEARNING_MYSQLPOOL_H