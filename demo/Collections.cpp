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

}


// 泛型，模版必须在函数前定义
template <typename T>
void showAllNumbers(const std::vector<T>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        std::cout << "数字为:"  << nums[i] << std::endl;
    }
}

void testMap() {

}