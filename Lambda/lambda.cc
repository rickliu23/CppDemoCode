#include <iostream>

int g_t = 5;

void lambda_test() {
    // 初始变量
    int x = 10;
    int y = 20;
    int z = 30;
    
    // 1. 无捕获 Lambda 可以访问全局变量, 不能访问局部变量
    auto no_capture = []() {
        std::cout << "global variable "  << g_t << ", ";
        // x = 20; // 这行会报错，因为 x 是局部变量
        return "A captureless lambda";
    };
    std::cout << "1. " << no_capture() << "\n";

    // 2. 值捕获 (x)， 访问副本，但不能修改（除非 mutable）
    auto capture_by_value = [x]() {
        return x;
    };
    std::cout << "2. Value capture (x): " << capture_by_value() << "\n";

    // 3. 引用捕获 (y)， 可以修改原值
    auto capture_by_reference = [&y]() {
        y = 100;
        return y;
    };
    std::cout << "3. reference capture (y): " << capture_by_reference() << "\n";
    std::cout << "   Original y modified: " << y << "\n";

    // 4. 混合捕获 (值捕获 x + 引用捕获 z)
    auto mixed_capture = [x, &z]() {
        z += x;
        return z;
    };
    std::cout << "4. Mixed capture(x value, z reference): " << mixed_capture() << "\n";

    // 5. 值捕获 + mutable 修改副本
    auto mutable_capture = [x]() mutable {
        x = 30;  // 修改副本 x（不影响原始变量）
        return x;
    };
    std::cout << "5. value capture by mutable: " << mutable_capture() << "\n";
    std::cout << "   Original x unchanged: " << x << "\n";
    
    // 6. 全局捕获 =（值捕获所有可见变量）
    auto capture_all_by_value = [=]() {
        // 可以访问但不能修改所有可见变量
        return "capture value: x=" + std::to_string(x) + 
               ", y=" + std::to_string(y) + 
               ", z=" + std::to_string(z);
    };
    std::cout << "6. Global capture by value: " << capture_all_by_value() << "\n";

    // 7. 全局捕获 &（引用捕获所有可见变量）
    auto capture_all_by_reference = [&]() {
        x = 40;  // 修改原始 x
        y = 50;  // 修改原始 y
        z = 60;  // 修改原始 z
        return "after modified: x=" + std::to_string(x) + 
               ", y=" + std::to_string(y) + 
               ", z=" + std::to_string(z);
    };
    std::cout << "7. Global capture by reference: " << capture_all_by_reference() << "\n";
    std::cout << "   Original value modified: x= " << x << ", y=" << y << ", z=" << z << "\n";
    
    // 8. 混合全局捕获 (大部分值捕获，指定引用捕获)
    auto mixed_global_capture = [=, &z]() {
        // 只有 z 可以被修改，其它是值捕获
        z = 100;
        return "now z = " + std::to_string(z);
    };
    std::cout << "8. Global capture by value + Capture z by Reference: " << mixed_global_capture() << "\n";
    std::cout << "   Original value modified: z= " << z << "\n";
}