cmake_minimum_required(VERSION 3.15)
project(learning)

set(CMAKE_CXX_STANDARD 20)

find_package(ODB 2.5.0 QUIET)
find_package(MySQL REQUIRED)
# 尝试查找系统已安装的ODB
# 下载后，设置ODB编译器路径
set(ODB_COMPILER ${odb_SOURCE_DIR}/bin/odb)
# 添加ODB头文件路径
include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${odb_SOURCE_DIR}  # ODB编译器头文件
)
# 创建可执行文件
file(GLOB_RECURSE SOURCES
        "*.cpp"
        "entity/*.cpp"
        "demo/*/*.cpp"
)

file(GLOB_RECURSE HEADERS
        "*.h"
        "include/*.h"
        "entity/*.h"
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS}
        entity/model/User.cpp
        include/User.h
        config/MysqlDb.cpp
        include/MysqlDb.h
        mapper/UserDao.cpp
        include/UserDao.h)# 创建可执行文件


