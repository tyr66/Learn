#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <chrono>


int main() {

    std::mutex tex;
    std::condition_variable cv;

    std::thread t0([&]{
        std::unique_lock<std::mutex> lck(tex);
        cv.wait(lck);
        std::cout << "t0 awake" << std::endl;
    });


    std::thread t1([&]{
        std::unique_lock<std::mutex> lck(tex);
        cv.wait(lck);
        std::cout << "t1 awake" << std::endl;
    });

    std::thread t2([&]{
        std::unique_lock<std::mutex> lck(tex);
        cv.wait(lck);
        std::cout << "t2 awake" << std::endl;
    });

    std::cout << "notify one thrread" << std::endl;
    cv.notify_one();

    std::this_thread::sleep_for(std::chrono::seconds(3));

    std::cout << "notify all thread" << std::endl;

    cv.notify_all();

    t0.join();
    t1.join();
    t2.join();

    return 0;
}
