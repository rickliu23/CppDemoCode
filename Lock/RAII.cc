#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

std::mutex print_mutex; // 控制输出锁
std::mutex data_mutex;  // 数据保护锁
int shared_data = 0;

void thread_work(int id) {
    // 1. 保护输出操作
    {
        // 如果去掉锁，这里可能会出现数据竞争，导致输出混乱
        std::lock_guard<std::mutex> print_lock(print_mutex);
        std::cout << "Thread " << id << " started\n";
    }
    
    // 2. 保护共享数据
    for (int i = 0; i < 1000; ++i) {
        std::lock_guard<std::mutex> data_lock(data_mutex);

        // 理论上不加锁这里会有问题，实测没测出来
        shared_data++; // 安全修改共享数据
    }
    
    // 3. 结束通知
    {
        std::lock_guard<std::mutex> print_lock(print_mutex);
        std::cout << "Thread " << id << " finished\n";
    }
}

void raii_test() {
    const int num_threads = 10;
    std::vector<std::thread> threads; // 创建动态线程容器，用于统一管理所有工作线程
    
    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back(thread_work, i); // 在容器末尾直接构造新元素
    }
    
    for (auto& t : threads) {
        t.join(); // 阻塞，等待所有线程完成
    }
    
    std::cout << "Final shared_data value: " << shared_data << std::endl;
    // 正确输出: 10000 (10线程 * 1000次)
}