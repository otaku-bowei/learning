# 常规定义
cmake_minimum_required(VERSION 3.15)
project(learning)

# 设置c++参数
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
find_package(Protobuf REQUIRED)
# 查找 gRPC
find_package(gRPC REQUIRED)
# 创建可执行文件
file(GLOB_RECURSE SOURCES
        "*.cpp"
        "src/entity/*.cpp"
        "src/service/*.cc"
        "src/service/*/*.cc"
        "demo/*/*.cpp"
)
file(GLOB_RECURSE HEADERS
        "*.h"
        "include/*.h"
        "src/entity/*.h"
        "src/service/*.h"
        "src/service/*/*.h"
)

# 包引入，定义包的编译后的执行路径，并关联头文件
set(ODB_COMPILER ${odb_SOURCE_DIR}/bin/odb)
set(BOOST_INCLUDE_DIRS ${libodb-boot_SOURCE_DIR}/bin/boot)
include_directories(
        include
        /usr/include
        /usr/include/grpcpp
        ${odb_SOURCE_DIR}  # ODB编译器头文件
        ${BOOST_INCLUDE_DIRS}
)
link_directories(/usr/lib/x86_64-linux-gnu)
link_libraries(
        odb
        odb-mysql
        odb-sqlite
        mysqlclient
        libodb-boot
        sqlite3
        pthread
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS}
        src/entity/model/User.cpp
        include/User.h
        include/User-odb.cxx
        include/User-odb.hxx
        include/User-odb.ixx
        src/config/MysqlDb.cpp
        include/MysqlDb.h
        src/mapper/UserDao.cpp
        include/UserDao.h
        demo/p6/gRPC.cpp
        include/gRPC.h)# 创建可执行文件



# 添加编译定义
target_compile_definitions(${PROJECT_NAME} PRIVATE
        BOOST_DATE_TIME_POSIX_TIME_STD_CONFIG
        BOOST_ALL_NO_LIB
)