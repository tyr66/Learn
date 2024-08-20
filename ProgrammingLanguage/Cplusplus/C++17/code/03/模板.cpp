#include <iostream>
#include <string>
#include <type_traits>

// template<class T, typename = std::enable_if_t<std::is_arithmetic<T>::value>>
// T twice(T a){
//     return a * 2;
// }

template<class T, typename = std::enable_if_t<!std::is_same<T, const char*>::value>>
T twice(T a) {
    return a * 2;
}

std::string twice(std::string s) {
    return s + s;
}

template<class T>
void func(T a) {
    std::cout << "调用了通用类型模板" << std::endl;
}

template<class T>
typename std::enable_if<std::is_same<T, float>::value>::value func(T a) {
    std::cout << "调用了需要编译器推导的特化类型" << std::endl;
}


void func(float a) {
    std::cout << "调用了不需要编译器推导的特化类型" << std::endl;
}

int main() {
    std::cout << twice(2) << std::endl;
    std::cout << twice(1.2) << std::endl;
    std::cout << twice(1.1f) << std::endl;
    std::cout << twice("hello ") << std::endl;

    func(1.0f);
    func(2.0);
    return 0;
}
