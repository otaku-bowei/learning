//
// Created by defsoul on 2026/1/26.
//

#include "../include/ConnectionSingleton.h"

std::unique_ptr<ConnectionGuard> ConnectionSingleton::con_ = nullptr;

std::unique_ptr<ConnectionGuard> ConnectionSingleton::getConnectionInstance() {
    if (con_.get() ==  nullptr) {
        MysqlPool pool(8);
        con_  =  std::make_unique<ConnectionGuard>(pool);
    }
    return std::move(con_);
}