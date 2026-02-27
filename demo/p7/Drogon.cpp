//
// Created by hp on 2026/2/25.
//

#include "../../include/Drogon.h"
#include <iostream>
#include <drogon/drogon.h>

void handle() {
    // 注册 UserController
    // app().registerController(std::make_shared<UserController>());
    std::cout << "Handler started" << std::endl;
    // 配置并启动
    // app().enableReusePort(8080);
    app().addListener("0.0.0.0", 8080, false);
    // app().setLogLevel(trantor::Logger::INFO);
    // 运行
    app().run();
}


void autowired() {
    kgr::container container;

    container.invoke([](UserController &ctrl) {
        ctrl.testInjection();
    });
}