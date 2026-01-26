//
// Created by 王柏伟 on 2026/1/17.
//

#include "../../include/ORM.h"

void insertOneUser() {
    std::vector<std::unique_ptr<SimpleUser>> entities;
    entities.push_back(std::make_unique<SimpleUser>(1, "aaa", "adawd", 5));
    insertBatchUser(entities, 1000);
}