# 常规定义
cmake_minimum_required(VERSION 3.15)
project(learning)

# 设置c++参数
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_TRY_COMPILE_OBJECT_PREFIX "")
add_compile_definitions(_GLIBCXX_USE_CXX11_ABI=1)


# 创建可执行文件
file(GLOB_RECURSE SOURCES
#        "*.cpp"
        "src/entity/*.cpp"
        "demo/*/*.cpp"
        "src/entity/model/*.cpp"
        "src/mapper/*.cpp"
        "include/*.cpp"
        "src/config/*.cpp"
        "src/controller/*.cpp"
)
file(GLOB_RECURSE ODB_SOURCES
        "src/entity/model/*.cxx"
        "src/entity/model/*.hxx"
#        "src/entity/model/*.ixx"
)
# .ixx 文件只用于包含，不编译
set(ODB_TEMPLATES
        "src/entity/model/*.ixx"
)
file(GLOB_RECURSE HEADERS
        "*.h"
        "src/entity/*.h"
        "demo/*/*.h"
        "src/entity/model/*.h"
        "src/mapper/*.h"
        "include/*.h"
        "src/config/*.h"
        "src/controller/*.h"
)

file(GLOB_RECURSE GRPC_SOURCE
        "src/service/*.h"
        "src/service/*.cc"
        "src/service/grpc/*.h"
        "src/service/grpc/*.cc"
)




# 包引入，定义包的编译后的执行路径，并关联头文件
set(BASE_INCLUDE_DIRS /usr/include)  # Linux默认路径

set(ODB_COMPILER ${BASE_INCLUDE_DIRS}/odb)
set(BOOST_INCLUDE_DIRS ${BASE_INCLUDE_DIRS}/odb/boost)
set(DROGON_INCLUDE_DIRS ${BASE_INCLUDE_DIRS}/drogon)
set(JSON_INCLUDE_DIRS ${BASE_INCLUDE_DIRS}/jsoncpp)
set(TRANTOR_INCLUDE_DIRS ${BASE_INCLUDE_DIRS}/trantor)
set(SPDLOG_INCLUDE_DIRS ${BASE_INCLUDE_DIRS}/spdlog)

# 获取完整依赖
find_package(PkgConfig REQUIRED)
#pkg_check_modules(GRPC REQUIRED grpc++ grpc)
pkg_check_modules(PROTOBUF REQUIRED protobuf)

include_directories(
        include
        ${BASE_INCLUDE_DIRS}
        ${ODB_COMPILER}  # ODB编译器头文件
        ${BOOST_INCLUDE_DIRS}
        ${DROGON_INCLUDE_DIRS}
        ${JSON_INCLUDE_DIRS}
        ${TRANTOR_INCLUDE_DIRS}
        ${SPDLOG_INCLUDE_DIRS}

)
link_directories(/usr/lib/x86_64-linux-gnu)
link_libraries(
        -lstdc++
        -lstdc++fs
        -lrt
        -ldl
        odb
        odb-mysql
        odb-sqlite
        mysqlclient
        odb-boost
        sqlite3
        pthread
        drogon
        trantor
        jsoncpp
        spdlog
)
# 创建可执行文件
add_executable(learning main.cpp
        ${SOURCES}
        ${ODB_SOURCES}
        ${HEADERS}
        src/config/Logger.cpp
        include/Logger.h
        src/constant/LogEnum.cpp
        include/LogEnum.h
)


# 添加编译定义
target_compile_definitions(${PROJECT_NAME} PRIVATE
        BOOST_DATE_TIME_POSIX_TIME_STD_CONFIG
        BOOST_ALL_NO_LIB
)