cmake_minimum_required(VERSION 4.1)
project(learning)

set(CMAKE_CXX_STANDARD 20)

add_executable(learning main.cpp
        entity/Animal.cpp
        entity/Animal.h
        entity/Cat.h
        entity/Cat.cpp
        entity/Cat.h
        entity/Dog.cpp
        entity/Dog.h
        entity/AnimalManager.cpp
        entity/AnimalManager.h
        demo/Polymorphism.cpp
        demo/Polymorphism.h)
