#include <iostream>
using namespace std;

int main()
{
    int x = 10;
    int y = 3;

    printf("x >= 0, y > 0, x/y = %d\n", x / y);

    x = -10;
    printf("x < 0, y > 0, x/y = %d\n", x / y);
    return 0;
}
