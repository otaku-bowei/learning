//
// Created by hp on 2026/2/27.
//

#include "../../include/Init.h"
#include <iostream>
#include <drogon/drogon.h>
#include <kangaru/autowire.hpp>

#include "UserController.h"

void initLogger() {

}
void initKangaru() {
    kgr::container container;

    // We invoke a lambda that receives injected parameters.
    // The container will figure how to wire the classes using
    // either the constructor parameters or aggregate initialization
    // container.invoke();
    std::cout << "Kangaru 容器初始化完成" << std::endl;
}

void initSqlPool() {

}


void initController() {
    app().registerController(std::make_shared<UserController>());

    std::cout << "Handler started" << std::endl;
    app().addListener("0.0.0.0", 8080, false);
    app().run();
}