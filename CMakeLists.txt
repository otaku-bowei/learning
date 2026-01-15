cmake_minimum_required(VERSION 4.1)
project(learning)

set(CMAKE_CXX_STANDARD 20)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(learning main.cpp
        entity/Animal.cpp
        include/Animal.h
        include/Cat.h
        entity/Cat.cpp
        include/Cat.h
        entity/Dog.cpp
        include/Dog.h
        entity/AnimalManager.cpp
        include/AnimalManager.h
        demo/p1/Polymorphism.cpp
        include/Polymorphism.h
        demo/p2/Collections.cpp
        include/Collections.h
        demo/p3/LambdaTest.cpp
        include/LambdaTest.h
        entity/TrainAnimal.cpp
        include/TrainAnimal.h
        demo/p4/DesignModel.cpp
        include/DesignModel.h
        entity/CatFamily.cpp
        include/CatFamily.h
        entity/DogFamily.cpp
        include/DogFamily.h)
