//
// Created by 王柏伟 on 2026/1/18.
//

#include "../include/UserDao.h"


void insertBatchUser(const std::vector<std::unique_ptr<User>> &entities, const int batch_size) {
    const auto con = ConnectionSingleton::getConnectionInstance();
    const auto db = con -> get();
    const int total = entities.size();
    for (int i = 0; i < total; i += batch_size) {
        // 计算当前批次的大小
        const int current_batch_size = std::min(batch_size, total - i);
        // 开始一个事务
        odb::transaction t(db -> begin());
        for (int j = 0; j < current_batch_size; ++j) {
            User *u = entities[i + j].get();
            db -> persist(u);
        }
        t.commit();
        std::cout << "已插入 " << i + current_batch_size << " 条记录，共 " << total << " 条" << std::endl;
    }
}

void insertUser(const std::unique_ptr<User> &entity) {
    const auto con = ConnectionSingleton::getConnectionInstance();
    const auto db = con -> get();
    // 开始一个事务
    odb::transaction t(db -> begin());
    db -> persist(entity.get());
    t.commit();
    std::cout << "已插入 " << entity.get() << std::endl;
}


std::vector<std::unique_ptr<User>> queryUsers(const std::string &db_name) {
    return {};
}


void updateUser(const std::unique_ptr<User> &entity) {

}


void deleteUser(const std::unique_ptr<User> &entity) {

}



