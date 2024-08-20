#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

class MTVector {
    std::vector<int> m_arr;
    std::mutex m_mtx;

public:
    class Accessor {
        MTVector &m_that;
        std::unique_lock<std::mutex> m_guard;

    public:
        Accessor(MTVector& vec): m_that(vec), m_guard(vec.m_mtx) {

        }

        void push_back(int val) const {
            m_that.m_arr.push_back(val);
        }
        size_t size() const {
            return m_that.m_arr.size();
        }
    };

    Accessor access() {
        return {*this};
    }

};

int main()
{
    MTVector mtv;

    std::thread t0([&]{
        auto accessor = mtv.access();
        for (int i = 0; i < 1000; i++)
            accessor.push_back(i);
    });

    std::thread t1([&]{
        auto accessor = mtv.access();
        for (int i = 0; i < 1000; i++)
            accessor.push_back(i);
    });

    t0.join();
    t1.join();

    return 0;
}
