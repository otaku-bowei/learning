//
// Created by defsoul on 2026/1/26.
//

#include "../include/ConnectionGuard.h"

ConnectionGuard::ConnectionGuard(MysqlPool& pool) : pool_(pool) {
    db_ = pool_.getConnection();
}

ConnectionGuard::~ConnectionGuard() {
    if (db_) {
        pool_.releaseConnection(db_);
    }
}

std::shared_ptr<odb::mysql::database> ConnectionGuard::get() {
    return db_;
}
