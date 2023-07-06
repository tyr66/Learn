#include <iostream>
#include <string>

using namespace std;

class Tmp{
public:
  Tmp(const Tmp&a){cout << "copy construct called" << endl;}
  Tmp(Tmp&&a) {cout << "move construct called" << endl;}
  Tmp() = default;
};

class Tmp2{
public:
  Tmp2(const Tmp2&a){cout << "tmp2 copy construct called" << endl;}
  //Tmp2(Tmp2&&a) = delete;
  Tmp2() = default;
  ~Tmp2(){cout << "Tmp2 destruct called" << endl;}
};

class A {
public:
  Tmp tmp;  
  Tmp2 tmp2;
};

int main()
{
  A a;
  A a1 = a;
  A a2 = std::move(a);
  cout << "-----------------" <<endl;

  printf("a2.tmp = %p, a.tmp = %p\n", &(a2.tmp), &(a2.tmp2));

  return 0;
}
