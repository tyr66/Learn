#include "Vector.h"
#include <iostream>

using namespace std;

void test1()
{
    cout << "test1 -------------" << endl;
    size_t sz = 10;
    Vector v(sz);

    for (int i = 0; i < sz; i++) {
        v[i] = i;
    }

    Vector v1 = v;

    Vector v2; v2 = v1;

    cout << "v : " << endl;
    v.print();

    cout << "v1 : " << endl;
    v1.print();

    cout << "v2 : " << endl;
    v2.print();
}

void test2()
{

    cout << "test2 -------------" << endl;
    size_t sz = 10;
    Vector v(sz);

    for (int i = 0; i < sz; i++) {
        v[i] = i;
    }

    cout << "v : " << endl;
    v.print();

    Vector v1 = std::move(v);

    cout << "v : " << endl;
    v.print();


    cout << "v1 : " << endl;
    v1.print();


    Vector v2; v2 = std::move(v1);

    cout << "v1 : " << endl;
    v1.print();

    cout << "v2 : " << endl;
    v2.print();
}


int main()
{
    test1();
    test2();
    return 0;
}
