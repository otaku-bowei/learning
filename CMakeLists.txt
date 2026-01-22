cmake_minimum_required(VERSION 3.15)
project(learning)

set(CMAKE_CXX_STANDARD 20)

# 可选：使用FetchContent自动获取ODB
include(FetchContent)

FetchContent_Declare(
        odb
        URL http://www.codesynthesis.com/download/odb/2.5.0/odb-2.5.0.tar.gz
)
FetchContent_Declare(
        libodb-mysql
        URL http://www.codesynthesis.com/download/odb/2.5.0/libodb-mysql-2.5.0.tar.gz
)
FetchContent_Declare(
        libodb
        URL http://www.codesynthesis.com/download/odb/2.5.0/libodb-2.5.0.tar.gz
)
FetchContent_MakeAvailable(odb libodb-mysql libodb)

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


# 创建libodb目标
add_library(libodb_headers INTERFACE)
# 创建libodb-mysql头文件接口库
add_library(libodb_mysql_headers INTERFACE)
add_library(odb_headers INTERFACE)
target_include_directories(libodb_mysql_headers INTERFACE
        ${libodb-mysql_SOURCE_DIR}
)
target_include_directories(libodb_headers INTERFACE
        ${libodb_SOURCE_DIR}
)
target_include_directories(odb_headers INTERFACE
        ${odb_SOURCE_DIR}
)

# 创建主可执行文件后链接
target_link_libraries(${PROJECT_NAME} PRIVATE
        libodb_headers
        libodb_mysql_headers
        odb_headers
)


