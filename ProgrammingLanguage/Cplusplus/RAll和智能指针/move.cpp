#include <iostream>
#include <string>
#include <vector>

using namespace std;

class A {

public:
  A(string _name):name(_name){}
  ~A(){cout << name << " was deleted!!! "<< endl;}
  
  string name;
};

class B {
public:
};

class C{
public:

};


void test1()
{
  cout << "test1 ------------------" << endl;

  string a1 = "tyr";
  string a2 = "dddsdlfjsldfjsldkjflkajfjdflkajdfjasdfkalkdfjafdsldfdsafldjfalk;sjfsjofian";

  a1 = std::move(a2);

  cout << "a1 = " << a1 << endl;
  cout << "a2 = " << a2 << endl;
  
  printf("&a1 = %p\n", a1.data());
  printf("&a2 = %p\n", a2.data());
}

void test2()
{
  cout << "test2 ------------------" << endl;
  vector<int> a1(10);
  vector<int> a2(20);

  a1 = std::move(a2);

  cout << "a1 size is " << a1.size() << endl;
  cout << "a2 size is " << a2.size() << endl;

  return;
}


void test3()
{
  int a1 = 1;
  int a2 = 2;

  a1 = std::move(a2);

  cout << "a1 = " << a1 << "&a1 = " << &a1 << endl;
  cout << "a2 = " << a2 <<"&a2 = " << &a2 << endl;
}


int main()
{
  test1();
  test2();
  test3();

  return 0;
}
