//
// Created by hp on 2026/1/8.
//

#include "Collections.h"

#include <algorithm>


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
    for (int i = 0; i < 5; i++) {
        std::cout << "数字为:"  << nums[i] << std::endl;
    }
    //4.排序
    std::sort(nums.begin() + 2, nums.end() - 1);


}

void showAllNumbers(std::vector<T> nums) {
    for (int i = 0; i < 5; i++) {
        std::cout << "数字为:"  << nums[i] << std::endl;
    }
}

void testMap() {

}