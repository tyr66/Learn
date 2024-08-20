#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <mutex>

class ThreadPool {

    std::vector<std::thread> _pool;

public:

    void push_back(std::thread t) {
        _pool.push_back(std::move(t));
    }

    ~ThreadPool() {
        for (auto& t : _pool) {
            t.join();
        }
    }
};

ThreadPool thread_pool;

void download(const std::string& name) {

    for (int i = 0; i <= 10; i++) {
        std::cout << "Downloaded....." << i * 10 << "% "<<std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(4));
    }

    std::cout << name << "download Finished" << std::endl;
}



void interact() {
    std::string msg;
    std::cin >> msg;
    std::cout << msg << std::endl;
}

void func_join() {
    std::thread t([&](){download("hello.zip");});
    interact();

    std::cout << "Waitting download thread finish" << std::endl;
    t.join();
}

void func_detach() {
    std::thread t([&]{download("hello.zip");});
    t.detach();
    interact();
}

void func_pool() {
    std::thread t([&]{download("hello.zip");});
    thread_pool.push_back(std::move(t));

    interact();
}


int main() {

    //func_detach(); // detach后的线程在main函数返回后会立刻被销毁
    func_pool();
    return 0;
}
