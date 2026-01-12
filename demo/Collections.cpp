//
// Created by hp on 2026/1/8.
//

#include "Collections.h"




void testVector() {
    //1.创建一个vector
    std::vector<int> nums;
    //2.写入随机数到vector
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    for (int i = 0; i < 5; i++) {
        nums.push_back(dis(gen));
    }
    //3.遍历vector
    showAllNumbers(nums);
    //4.排序
    std::ranges::sort(nums.begin() + 2, nums.end() - 1);
    std::cout << "进行排序后"<< std::endl;
    showAllNumbers(nums);

    std::ranges::sort(nums);
    std::cout << "进行排序后"<< std::endl;
    showAllNumbers(nums);

    //5.去重--只删除相邻的重复函数
    for (int i = 0; i < 100; i++) {
        nums.push_back(dis(gen));
    }
    showAllNumbers(nums);
    std::ranges::sort(nums);
    auto [new_begin, new_end] = std::ranges::unique(nums.begin(), nums.end());
    // showAllNumbers(nums);
    nums.erase(new_begin, new_end);
    std::cout << nums.size() << std::endl;

    //6.做对象的去重
    std::vector<Animal*> animalVector;
    auto dog1 = std::make_unique<Dog>("吉娃娃", 1);
    auto dog2 = std::make_unique<Dog>("马犬", 3);
    auto cat1 = std::make_unique<Cat>("王百万", true, 5);
    animalVector.push_back(std::make_unique<Dog>("吉娃娃", 1));
    animalVector.push_back(std::make_unique<Dog>("马犬", 3));
    animalVector.push_back(std::make_unique<Cat>("王百万", true, 5));



}


// 泛型，模版必须在函数前定义，使用断言来判断泛型上下界
template <typename T>
void showAllNumbers(const std::vector<T>& nums) {
    static_assert(std::is_integral_v<T>, "T必须是整数类型");
    for (int i = 0; i < nums.size(); i++) {
        std::cout << "数字为:"  << nums[i] << std::endl;
    }
}

void testMap() {

}