#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <array>

int func(int a, int b) {
    int c = a + b;
    int d = a - b;
    return (c + d) / 2;
}

int func_sum() {

    int res = 0;
    for (int i = 1; i < 500; i++) {
        res += i;
    }
    return res;
}

int func_sum2() {
    int res = 0;
    for (int i = 0; i <= 5000; i++) {
        res += i;
    }
    return res;
}

int func_sum_vector() {
    std::vector<int> arr;
    for (int i = 1; i <= 500; i++) {
        arr.push_back(i);
    }
    return std::reduce(arr.begin(), arr.end());
}

int func_sum_array() {
    std::array<int,500> arr;
    for (int i = 0; i < 500; i++)
        arr[i] = i;
    return std::reduce(arr.begin(), arr.end());
}


constexpr int func_sum_array2() {
    std::array<int,500> arr{};
    for (int i = 0; i < 500; i++)
        arr[i] = i;
    int res = 0;
    for (int i = 0; i < 500; i++)
        res += arr[i];
    return res;
}

int func2() {
    return func_sum_array2();
}

