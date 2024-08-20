#include <iostream>
#include <chrono>

int main()
{
    auto t0 = std::chrono::steady_clock::now();
    for (int i = 0; i <= 100000; i++);
    auto t1 = std::chrono::steady_clock::now();

    auto t = t1 - t0;

    using double_ms = std::chrono::duration<double, std::milli>;
    double ms = std::chrono::duration_cast<double_ms>(t).count();

    std::cout << "time : " << ms << "ms" << std::endl;

    return 0;
}
