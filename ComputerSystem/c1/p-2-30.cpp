#include <iostream>

int tadd_ok(int x, int y) {
    return ( x > 0 && y > 0) ? !(x + y < 0) : (x < 0 && y < 0) ? !(x + y >= 0) : 1 ;
}

int tadd_ok2(int x, int y) {
    int sum = x + y;
    return (sum - x == y) && (sum - y == x);
}

void test_minus_overflow() {

    int x =INT_MIN;

    for (int y = -1;y >= INT_MIN && y < 0; y--) {
        if (tadd_ok(x, y)) {
            std::cout << "minus_overflow test failed x = " << x << ", y = " << y << ", x + y = " << x + y << std::endl;
            return;
        }
    }

    std::cout << "minuse overflow test passed" << std::endl;
}

void test_positive_overflow() {
    int x = INT_MAX;

    for (int y  = 1; y <= INT_MAX && y > 0; y++) {
        if (tadd_ok(x, y)) {
            std::cout << "opsitive_overflow test failed x = " << x << ", y = " << y << std::endl;
            return;
        }
    }

    std::cout << "opsitive overflow test passed" << std::endl;

}

void test_INT_MIN() {
    std::cout << "test INT_MIN overflow: ";
    if (tadd_ok(1, INT_MIN) == 1&& tadd_ok(-1, INT_MIN) == 0) {
        std::cout << "passed";
    }
    std::cout << std::endl;
}

void test_add2() {

    std::cout << "test add2" << std::endl;

    int x = INT_MAX;
    for (int y  = 1; y <= INT_MAX && y > 0; y++) {
        if (tadd_ok2(x, y)) {
            std::cout << "opsitive_overflow test failed x = " << x << ", y = " << y << std::endl;
            return;
        }
    }

    x = INT_MIN;
    for (int y = -1;y >= INT_MIN && y < 0; y--) {
        if (tadd_ok(x, y)) {
            std::cout << "minus_overflow test failed x = " << x << ", y = " << y << ", x + y = " << x + y << std::endl;
            return;
        }
    }
}

int main() {

    test_minus_overflow();
    test_positive_overflow();
    test_INT_MIN();
    test_add2();

    return 0;
}
