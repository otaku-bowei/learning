//
// Created by defsoul on 2026/1/26.
//

#ifndef LEARNING_CONNECTIONSINGLETON_H
#define LEARNING_CONNECTIONSINGLETON_H


#include <iostream>
#include "ConnectionGuard.h"

class ConnectionSingleton {
private:
    static std::unique_ptr<ConnectionGuard> con_;

private:
    ConnectionSingleton() = default;
    ~ConnectionSingleton() = default;
    
    // 禁止拷贝和赋值
    ConnectionSingleton(const ConnectionSingleton&) = delete;
    ConnectionSingleton& operator=(const ConnectionSingleton&) = delete;
    
    // 禁止移动
    ConnectionSingleton(ConnectionSingleton&&) = delete;
    ConnectionSingleton& operator=(ConnectionSingleton&&) = delete;

public:
    static std::unique_ptr<ConnectionGuard> getConnectionInstance();
};


#endif //LEARNING_CONNECTIONSINGLETON_H