//
// Created by 王柏伟 on 2026/1/14.
//

#include "../../include/LambdaTest.h"


// void tryToTrainAnimalSayOtherThings(const std::function<std::string(void)>& trainSomeThing) {
//     trainSomeThing("我会Python", [](){
//         std::cout << "训练一下!" << std::endl;
//     });
// }


// 方法1：使用std::function
void tryToTrainAnimalSayOtherThings1(const std::string &sentence,
                                     const std::function<void(std::string)> &func) {
    func(sentence);
}

// 方法2：使用函数指针（仅适用于无捕获的lambda）
void tryToTrainAnimalSayOtherThings2(const std::string &sentence,
                                     void (*func)(std::string)) {
    func(sentence);
}

// 方法 3.使用模版函数
template<typename Func>
void tryToTrainAnimalSayOtherThings3(const std::string &sentence, Func func) {
    func(sentence);
}

void saySomething(const std::string &sentence) {
    std::cout << sentence << std::endl;
};

void testLambdaTest() {
    std::cout << "LambdaTest" << std::endl;
    auto cat1 = std::make_unique<Cat>("王百万",  true, 5);
    auto dog1 = std::make_unique<Dog>("coco", 5);
    //1.将函数赋值给某个变量
    auto dogSayFunc = [capture0 = dog1.get()](auto && PH1) { capture0->makeAnimalSayOtherThings(std::forward<decltype(PH1)>(PH1)); };
    tryToTrainAnimalSayOtherThings1("我要学Python ", dogSayFunc);
    //2.直接进行操作
    tryToTrainAnimalSayOtherThings1("我要把杯子推下去 ", [cat = cat1.get()](const std::string &sentence) {
        cat -> makeAnimalSayOtherThings(sentence);
    });

    //3.实现第二种方法--不支持有捕获的方法
    void (*saySomethingLambda)(std::string) = [](const std::string sentence) {
        saySomething(sentence);
    };
    tryToTrainAnimalSayOtherThings2("我要再把杯子推下去 ", saySomethingLambda);

    //4.实现第三 种方式
    tryToTrainAnimalSayOtherThings3("我还要再把杯子推下去 ", [cat = cat1.get()](const std::string &sentence) {
        cat -> makeAnimalSayOtherThings(sentence);
    });


};
