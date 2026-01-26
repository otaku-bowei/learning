//
// Created by defsoul on 2026/1/26.
//

#ifndef LEARNING_CONNECTIONGUARD_H
#define LEARNING_CONNECTIONGUARD_H

#include <MysqlPool.h>

class ConnectionGuard {
private:
    MysqlPool& pool_;
    std::shared_ptr<odb::mysql::database> db_;

public:
    ConnectionGuard(MysqlPool& pool);

    ~ConnectionGuard();

    std::shared_ptr<odb::mysql::database> get();

    // 禁用复制
    ConnectionGuard(const ConnectionGuard&) = delete;
    ConnectionGuard& operator=(const ConnectionGuard&) = delete;

    // 允许移动
    ConnectionGuard(ConnectionGuard&& other) noexcept: pool_(other.pool_), db_(std::move(other.db_)) {
    };

};



#endif //LEARNING_CONNECTIONGUARD_H