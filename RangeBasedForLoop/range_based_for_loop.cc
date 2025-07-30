#include <iostream>
#include <vector>
#include <string>

// 函数1: 打印字符串向量
void printFruits(const std::vector<std::string>& fruits) {
    std::cout << "frult list:\n";
    for (const auto& fruit : fruits) {
        std::cout << " - " << fruit << "\n";
    }
}

// 函数2: 加倍向量中的数值并返回新向量
std::vector<int> doubleValues(const std::vector<int>& input) {
    std::vector<int> result = input;  // 创建副本
    
    // 使用引用修改元素
    for (auto& val : result) {
        val *= 2;
    }
    
    return result;
}

// 函数3: 计算向量总和
int calculateSum(const std::vector<int>& numbers) {
    int sum = 0;
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        sum += *it;
    }
    return sum;
}

void range_based_for_loop() {
    // 测试1: 字符串向量
    std::vector<std::string> fruits = {"apple", "banana", "orange", "Grape"};
    printFruits(fruits);
    
    // 测试2: 数值向量
    std::vector<int> values = {1, 2, 3, 4, 5};
    
    std::cout << "\nsource value: ";
    for (const auto& val : values) {
        std::cout << val << " ";
    }
    
    auto doubled = doubleValues(values);
    
    std::cout << "\nAfter doubling: ";
    for (const auto& val : doubled) {
        std::cout << val << " ";
    }

    // 测试3: 计算总和
    std::cout << "\n\nsum: " << calculateSum(values) 
              << " -> " << calculateSum(doubled) << "\n";
}