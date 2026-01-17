cmake_minimum_required(VERSION 4.1)
project(learning)

set(CMAKE_CXX_STANDARD 20)

# 可选：使用FetchContent自动获取ODB
include(FetchContent)

FetchContent_Declare(
        odb
        URL http://www.codesynthesis.com/download/odb/2.4/odb-2.4.0.tar.gz
)
FetchContent_Declare(
        libodb-mysql
        URL http://www.codesynthesis.com/download/odb/2.4/libodb-mysql-2.4.0.tar.gz
)
FetchContent_MakeAvailable(odb libodb-mysql)

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

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})# 创建可执行文件


#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
#
#add_executable(learning main.cpp
#        entity/Animal.cpp
#        include/Animal.h
#        include/Cat.h
#        entity/Cat.cpp
#        include/Cat.h
#        entity/Dog.cpp
#        include/Dog.h
#        entity/AnimalManager.cpp
#        include/AnimalManager.h
#        demo/p1/Polymorphism.cpp
#        include/Polymorphism.h
#        demo/p2/Collections.cpp
#        include/Collections.h
#        demo/p3/LambdaTest.cpp
#        include/LambdaTest.h
#        entity/TrainAnimal.cpp
#        include/TrainAnimal.h
#        demo/p4/DesignModel.cpp
#        include/DesignModel.h
#        entity/CatFamily.cpp
#        include/CatFamily.h
#        entity/DogFamily.cpp
#        include/DogFamily.h
#        demo/p5/ORM.cpp
#        include/ORM.h
#
#)
