#include <iostream>

int uadd_ok(unsigned x, unsigned y) {
    return x + y >= x;
}

int main() {

    unsigned x = UINT_MAX - 2;
    unsigned y = 2;

    if (uadd_ok(x, y)) {
        std::cout << "No overflow x = " << x << ", y = " << y << std::endl; 
    } else {
        std::cout << "overflowed x = " << x << ", y = " << y << std::endl; 
    }

    return 0;
}
