//
// Created by 王柏伟 on 2026/1/14.
//

#ifndef LEARNING_LAMBDATEST_H
#define LEARNING_LAMBDATEST_H
#include <functional>
#include <iostream>
#include <ostream>
#include <string>
#include <memory>
#include "Cat.h"
#include "Dog.h"
#include "Animal.h"

class LambdaTest {
};


void tryToTrainAnimalSayOtherThings1(const std::string &sentence, const std::function<void(std::string)>& func);

// 方法2：使用函数指针（仅适用于无捕获的lambda）
void tryToTrainAnimalSayOtherThings2(const std::string &sentence, void (*func)(std::string));

template<typename Func>
void tryToTrainAnimalSayOtherThings3(const std::string &sentence, Func func);

void saySomething(const std::string &sentence);

void testLambdaTest();

#endif //LEARNING_LAMBDATEST_H