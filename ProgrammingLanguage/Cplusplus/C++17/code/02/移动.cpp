#include <iostream>
#include <type_traits>

class C {
public:
    int x,y;

};

template<class T>
void func(T&& c) {

    if (std::is_same_v<T, C&>) {
        std::cout << "T is C&" << std::endl;
    } else if (std::is_same_v<T, C>) {
        std::cout << "T is C" << std::endl;
    } else if (std::is_same_v<T, const C&>) {
        std::cout << "T is const C&" << std::endl;
    }


    if (std::is_same_v<C, std::decay_t<T>>) {
        std::cout << "C&& decay to C" << std::endl;
    }

    std::cout << "pass" << std::endl;
}


int main()
{
    C c;
    const C& a = c;
    func(a);
    return 0;
}
