//
// Created by 王柏伟 on 2026/1/18.
//

#ifndef LEARNING_USERDAO_H
#define LEARNING_USERDAO_H
#include <memory>   // std::unique_ptr
#include <iostream>
#include "ConnectionGuard.h"
#include "../src/entity/model/User-odb.hxx"
#include "ConnectionSingleton.h"
#include <kangaru/autowire.hpp>

class UserDao {
public:

    // 自动注入
    friend auto service_map(UserDao const&) -> kgr::autowire_single;

    //CURD
    /**
     * 批量插入用户
     * @param entities
     * @param batch_size
     */
    void insertBatchUser(const std::vector<std::unique_ptr<User>> &entities, const int batch_size = 1000);

    /**
     * 新增单个用户
     * @param entity
     */
    void insertUser(const std::unique_ptr<User> &entity);

    /**
     * 根据条件查询用户
     * @param db_name
     * @return
     */
    std::vector<std::unique_ptr<User>> queryUsers(const std::string &db_name);

    /**
     * 更新用户信息
     * @param entity
     */
    void updateUser(const std::unique_ptr<User> &entity);

    /**
     * 删除用户
     * @param entity
     */
    void deleteUser(const std::unique_ptr<User> &entity);

};

#endif //LEARNING_USERDAO_H