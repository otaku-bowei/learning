# 常规定义
cmake_minimum_required(VERSION 3.15)
project(learning)

# 设置c++参数
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# 创建可执行文件
#file(GLOB_RECURSE SOURCES
#        "*.cpp"
#        "entity/*.cpp"
#        "demo/*/*.cpp"
#        "entity/model/*.cpp"
#        "mapper/*.cpp"
#        "include/*.cpp"
#        "config/*.cpp"
#)
#file(GLOB_RECURSE ODB_SOURCES
#        "entity/model/*.cxx"
#        "entity/model/*.hxx"
#        "entity/model/*.ixx"
#)
#file(GLOB_RECURSE ODB_HEADER
#        "entity/model/*.hxx"
#        "entity/model/*.ixx"
#)
#file(GLOB_RECURSE HEADERS
#        "*.h"
#        "entity/*.h"
#        "demo/*/*.h"
#        "entity/model/*.h"
#        "mapper/*.h"
#        "include/*.h"
#        "config/*.h"
#)

# 包引入，定义包的编译后的执行路径，并关联头文件
set(BASE_INCLUDE_DIRS /usr/include)  # Linux默认路径


set(ODB_COMPILER ${BASE_INCLUDE_DIRS}/odb)
set(BOOST_INCLUDE_DIRS ${BASE_INCLUDE_DIRS}/odb/boost)
include_directories(
        include
        ${ODB_COMPILER}  # ODB编译器头文件
        ${BOOST_INCLUDE_DIRS}
#        ${HEADERS}

)
link_directories(/usr/lib/x86_64-linux-gnu)
link_libraries(
        odb
        odb-mysql
        odb-sqlite
        mysqlclient
        odb-boost
        sqlite3
        pthread
)

#add_executable(${PROJECT_NAME}
#        ${SOURCES}
#        ${ODB_SOURCES}
#)# 创建可执行文件
add_executable(learning
        # 根目录源文件
        main.cpp
        config/MysqlDb.cpp

        entity/Animal.cpp
        entity/AnimalManager.cpp
        entity/Cat.cpp
        entity/CatFamily.cpp
        entity/Dog.cpp
        entity/DogFamily.cpp
        entity/TrainAnimal.cpp

        # demo子目录源文件
        demo/p1/Polymorphism.cpp
        demo/p2/Collections.cpp
        demo/p3/LambdaTest.cpp
        demo/p4/DesignModel.cpp
        demo/p5/ORM.cpp

        # entity/model子目录源文件
        entity/model/User.cpp
        entity/model/SimpleUser.cpp
        entity/model/SimpleUser-odb.cxx

        # mapper子目录源文件
        mapper/UserDao.cpp
        config/MysqlPool.cpp
        include/MysqlPool.h
        config/ConnectionGuard.cpp
        include/ConnectionGuard.h
        config/ConnectionSingleton.cpp
        include/ConnectionSingleton.h
)



# 添加编译定义
target_compile_definitions(${PROJECT_NAME} PRIVATE
        BOOST_DATE_TIME_POSIX_TIME_STD_CONFIG
        BOOST_ALL_NO_LIB
)