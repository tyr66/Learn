#include <iostream>

using namespace std;

int main()
{
    int x = -12340;
    int k = 4;
    
    // 不同的除法运算
    printf("%d / %d = %d\n", x, 1 << k, x / (1 << k));
    // 进行移位运算
    printf("%d >> %d = %d\n", x, k, x >> k);
    //修正后的移位运算
    printf("(%d + 1 << %d - 1) >> %d = %d\n", x, k, 1 << k, (x + (1 << k) - 1) >> k);
    return 0;
}


