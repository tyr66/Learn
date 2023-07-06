#include <iostream>
#include <string>
#include <cstdlib>

#if defined(__GNUC__) || defined(__clang__) 
#include <cxxabi.h>
#endif

using namespace std;

template<class T>
string show_type()
{
    const char* name = typeid(T).name();
    string s = name;

#if defined(__GNUC__) || defined(__clang__) 
    int status;
    char *p = abi::__cxa_demangle(name, 0, 0, &status);
    s = p;
    std::free(p);
#endif

    if (std::is_const_v<std::remove_reference_t<T>>)
        s += " const";
    if (std::is_volatile_v<std::remove_reference<T>>)
        s += " volatile";
    if (std::is_lvalue_reference_v<T>)
        s += " &";
    if (std::is_rvalue_reference_v<T>)
        s += " &&";

    return s;
}

const int& func()
{
    static const int n = 10;
    return n;
}

void test1()
{
    int n = 10;
    int &m = n;

    std::remove_reference_t<decltype(m)> p = m;
    // decltype(m) p = m;
    p = 100;

    cout << "m = " << m << endl;
    cout << "p = " << p << endl;
}

void test2()
{
    int n = 10;
    int &m = n;
    cout << show_type<decltype(n)>() << endl;
    cout << show_type<decltype(m)>() << endl;
    cout << show_type<decltype(func())>() << endl;
}

int main()
{
    test1();
    test2();
    return 0;
}
