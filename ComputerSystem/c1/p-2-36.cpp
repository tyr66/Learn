#include <iostream>
#include <limits>
#include <vector>

bool tmult_ok(short x, short y) {

    int p = (int)x * y;

    return p == (short)p;
}

bool tmult_ok2(short x, short y) {

    short p = x * y;

    return !x || p / x == y;
}

void test_multok() {

    int cnt = (int)std::numeric_limits<short>::max() - std::numeric_limits<short>::min() + 1;
    short x = std::numeric_limits<short>::min(), y;

    // std::cout << cnt << std::endl;

    for (int i = 0; i < cnt; i++) {

        y = std::numeric_limits<short>::min();

        for (int j = 0; j < cnt; j++) {

            if (tmult_ok(x, y) != tmult_ok2(x, y)) {
                std::cout << "test_failed" << std::endl;
                return;
            }

            y++;

        }
        x++;
    }

    std::cout << "test_pass" << std::endl;
}

int main() {

    test_multok();
    return 0;
}
