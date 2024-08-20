#pragma once

#include <tbb/parallel_reduce.h>
#include <tbb/blocked_range.h>
#include <chrono>
#include <cmath>
#include <vector>
#include <iostream>


class Reduce {

private:

public:
    void run() {

        std::cout << "**********************parallel reduce test **********************" << std::endl;
        size_t N = 1 << 26;

        std::vector<float> arr(N);

        for (size_t i = 0; i < N; i++) {
            arr[i] = 10 + std::sin(i);
        }

        float avg = 0.0;
        for (size_t i = 0; i < N; i++) {
            avg += arr[i];
        }

        avg /= N;

        std::cout << "average by serial is " << avg << std::endl;

        avg = tbb::parallel_reduce(tbb::blocked_range<size_t>(0, N), (float)0, [&](tbb::blocked_range<size_t> r, float local_res){

            for (auto i = r.begin(); i != r.end(); i ++) {
                local_res += arr[i];
            }

            return local_res;

        }, [](float x, float y){return x + y;}) / N;

        std::cout << "average by parallel is " << avg << std::endl;
    }

};
