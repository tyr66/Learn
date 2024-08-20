#include <iostream>
#include <type_traits>




int main() {
    int&& a = 898;
    using decay_T = std::decay_t<decltype(a)>;

    if (std::is_same_v<int&&, decltype(a)>) {
        std::cout << "int&&" << std::endl;
    }

    if (std::is_same<decay_T, int&&>::value) {
        std::cout << "still int&&" << std::endl;
    } else if (std::is_same_v<decay_T, int>){
        std::cout << "decay to int" << std::endl;
    } else {
        std::cout << "decay to other else" << std::endl;
    }

    return 0;
}
