//
// Created by 王柏伟 on 2026/1/17.
//

#include "../../include/ORM.h"

void insertOneUser() {
    doSomething("insert into rbac.user(id, user_name, ppassword) values (1, 'aaa', 'aaaa')");
}