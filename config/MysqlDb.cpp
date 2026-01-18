//
// Created by 王柏伟 on 2026/1/18.
//

#include "../include/MysqlDb.h"


std::shared_ptr<odb::mysql::database> connect() {
    try {
        // 1. 创建MySQL数据库连接
        std::cout << "正在连接到 MySQL..." << std::endl;
        // 修改这些参数为你的MySQL配置
        auto user = "root";
        auto password = "IboTxData5566";  // 你的密码
        auto database = "rbac";  // 数据库名
        auto host = "localhost";
        unsigned int port = 3306;

        auto db = std::make_shared<odb::mysql::database>(
            user, password, database, host, port
        );
        return db;
    } catch (const odb::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return nullptr;
}

