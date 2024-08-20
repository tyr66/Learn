#include <iostream>

bool is_little_endian() {
    int n = 1;
    char* p = (char*)&n;
    return *p & 0x01;
}


int main() {

    if (is_little_endian()) {
        printf("is little endian\n");
    } else {
        printf("is big endian\n");
    }

    return 0;
}
