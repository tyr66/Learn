#include <iostream>
#include <iomanip>
#include <cstdint>

uint32_t A(uint32_t N) {
    return N & 0x000000FF;
}

uint32_t B(uint32_t N) {
    return N ^ 0xFFFFFF00;
}

uint32_t C(uint32_t N) {
    return N | 0x000000FF;
}


int main() {

    std::uint32_t N = 0;
    std::cin >> N;

    std::cout <<"A: 0x" << std::setw(8) << std::setfill('0') << std::hex << A(N) << std::endl;
    std::cout << "B: 0x" << std::setw(8) << std::setfill('0') << std::hex <<B(N) << std::endl;
    std::cout << "C: 0x" << std::setw(8) << std::setfill('0') << std::hex << C(N) << std::endl;

    return 0;
}
