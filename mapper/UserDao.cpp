//
// Created by 王柏伟 on 2026/1/18.
//

#include "../include/UserDao.h"


// void insertBatchUser(std::vector<std::unique_ptr<User>> &entities, const int batch_size = 1000) {
//     auto db = connect();
//     int total = entities.size();
//     for (int i = 0; i < total; i += batch_size) {
//         // 计算当前批次的大小
//         int current_batch_size = std::min(batch_size, total - i);
//         // 开始一个事务
//         odb::transaction t(db -> begin());
//         for (int j = 0; j < current_batch_size; ++j) {
//             User *u = entities[i + j].get();
//             db -> persist(u);
//         }
//         t.commit();
//         std::cout << "已插入 " << i + current_batch_size << " 条记录，共 " << total << " 条" << std::endl;
//     }
// }

void insertBatchUser(std::vector<std::unique_ptr<SimpleUser>> &entities, const int batch_size = 1000) {
    auto db = connect();
    int total = entities.size();
    for (int i = 0; i < total; i += batch_size) {
        // 计算当前批次的大小
        int current_batch_size = std::min(batch_size, total - i);
        // 开始一个事务
        odb::transaction t(db -> begin());
        for (int j = 0; j < current_batch_size; ++j) {
            SimpleUser *u = entities[i + j].get();
            db -> persist(u);
        }
        t.commit();
        std::cout << "已插入 " << i + current_batch_size << " 条记录，共 " << total << " 条" << std::endl;
    }
}


void doSomething(const std::string &sql) {
    auto db = connect();
    // 开始一个事务
    odb::transaction t(db -> begin());
    db->execute(sql);
    t.commit();
}
