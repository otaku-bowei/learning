//
// Created by hp on 2026/1/8.
//

#include "../../include/Collections.h"

#include <map>


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
    auto cat2 = std::make_unique<Cat>("王百万", true, 10);
    animalVector.push_back(cat2.get());
    animalVector.push_back(dog1.get());
    animalVector.push_back(dog2.get());
    animalVector.push_back(cat1.get());

    showAllAnimal(animalVector);
    std::ranges::sort(animalVector, [](Animal* a, Animal* b) {
        return a->equal(b);
    });
    auto [new_begin1, new_end1] = std::ranges::unique(animalVector.begin(), animalVector.end());
    //默认比较内存地址
    animalVector.erase(new_begin1, new_end1);
    showAllAnimal(animalVector);
    animalVector = remove_duplicates_keep_order(animalVector, [](const Animal* a) {return a->getName();});
    showAllAnimal(animalVector);


}


// 泛型，模版必须在函数前定义，使用断言来判断泛型上下界
template <typename T>
void showAllNumbers(const std::vector<T>& nums) {
    static_assert(std::is_integral_v<T>, "T必须是整数类型");
    for (int i = 0; i < nums.size(); i++) {
        std::cout << "数字为:"  << nums[i] << std::endl;
    }
}

template <typename U>
void showAllAnimal(const std::vector<U*>& animals) {
    static_assert(std::is_base_of_v<Animal, U>, "U必须是动物");
    auto animalManager = std::make_unique<AnimalManager>(animals);
    animalManager->countOff();
}

// 重新处理vector做去重
template<typename T, typename KeyFunc>
std::vector<T*> remove_duplicates_keep_order(const std::vector<T*>& items, KeyFunc key_func) {
    using KeyType = decltype(key_func(std::declval<T*>()));
    std::unordered_set<KeyType> seen;
    std::vector<T*> result;
    for(const auto &item : items) {
        if(auto key = key_func(item); !seen.contains(key)) {
            seen.insert(key);
            result.push_back(item);
        }
    }
    return result;
}

void testMap() {
    //1.测试 map的写入和查询
    std::map<std::string, Animal*> animalMap;
    const auto dog1 = std::make_unique<Dog>("吉娃娃", 1);
    const auto dog2 = std::make_unique<Dog>("马犬", 3);
    const auto cat1 = std::make_unique<Cat>("王百万", true, 5);
    const auto cat2 = std::make_unique<Cat>("王百万", true, 10);
    animalMap.insert(std::make_pair("dog1", dog1.get()));
    animalMap.insert(std::make_pair("dog2", dog2.get()));
    animalMap.insert(std::make_pair("王百万", cat1.get()));
    animalMap.insert(std::make_pair("王百万", cat1.get()));

    const Animal* a1 = animalMap["dog1"];
    std::cout << a1 -> getName() << std::endl;
    const Animal* a2 = animalMap["王百万"];
    std::cout << a2 -> getName() << std::endl;

    animalMap.insert(std::make_pair("王百万", cat1.get()));

    //2.遍历map
    for (const auto& [key, value] : animalMap) {
        std::cout << key << ":" << value -> getName() << std::endl;
        value->speak();
    }

}