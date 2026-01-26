//
// Created by defsoul on 2026/1/26.
//

#include "../include/MysqlPool.h"


MysqlPool::MysqlPool(size_t max_pool_size)
        : max_pool_size_(max_pool_size), current_size_(0) {

    // 设置连接参数
    user_ = "root";
    password_ = "IboTxData5566";
    database_ = "rbac";
    host_ = "172.19.176.1";
    port_ = 3306;
    socket_ = "";

    // 预先创建一些连接
    for (size_t i = 0; i < 3 && i < max_pool_size_; ++i) {
        auto conn = createConnection();
        if (conn) {
            pool_.push(conn);
            current_size_++;
        }
    }
}

std::shared_ptr<odb::mysql::database> MysqlPool::getConnection() {
    std::unique_lock<std::mutex> lock(mutex_);

    // 如果池中有可用连接
    if (!pool_.empty()) {
        auto conn = pool_.front();
        pool_.pop();
        return conn;
    }

    // 池为空但可以创建新连接
    if (current_size_ < max_pool_size_) {
        lock.unlock();
        auto conn = createConnection();
        if (conn) {
            std::lock_guard<std::mutex> guard(mutex_);
            current_size_++;
            return conn;
        }
    }

    // 等待连接释放
    while (pool_.empty()) {
        cond_.wait(lock);
    }

    auto conn = pool_.front();
    pool_.pop();
    return conn;
}

void MysqlPool::releaseConnection(std::shared_ptr<odb::mysql::database> conn) {
    if (!conn) return;

    // 检查连接是否仍然有效
    if (!testConnection(conn)) {
        std::cout << "连接已失效，创建新连接..." << std::endl;
        conn = createConnection();
    }

    std::lock_guard<std::mutex> lock(mutex_);
    pool_.push(conn);
    cond_.notify_one();
}

std::shared_ptr<odb::mysql::database> MysqlPool::createConnection() {
    try {
        auto conn = std::make_shared<odb::mysql::database>(
            user_.c_str(), password_.c_str(), database_.c_str(),
            host_.c_str(), port_, socket_
        );

        // 设置连接参数
        odb::transaction t(conn->begin());
        conn->execute("SET SESSION wait_timeout = 28800");
        t.commit();

        return conn;

    } catch (const odb::exception &e) {
        std::cerr << "创建连接失败: " << e.what() << std::endl;
        return nullptr;
    }
}


bool MysqlPool::testConnection(std::shared_ptr<odb::mysql::database> conn) {
    if (!conn) return false;

    try {
        odb::transaction t(conn->begin());
        conn->execute("SELECT 1");
        t.commit();
        return true;
    } catch (...) {
        return false;
    }
}