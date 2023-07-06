#include <iostream>
#include <string>

using namespace std;

class Pig {
public:
  explicit Pig(string str, int n):name(str), val(n){}
private:
  string name;
  int val;
};

class A {
public:
  int n;
  Pig pig{"tyr", 0};
};

class B {
public:
  int a;
  int b;
  int c{};

public:
  void show(){
    printf("a = %d, b = %d, c = %d\n", a, b, c);
  }

};

void show(Pig pig){

}

// C++ 显示构造函数和隐式构造函数
void test1(){
  //Pig pig1 = {"a", 909}; // 编译错误
  Pig pig2("tyr", 10.0); // 编译通过
  // Pig pig3{"tyr", 10.0}; // 编译不通过, 编译器不允许narrowing conversion {} 的初始化方式不允许强制类型转换，而()的初始化方式允许强制类型转换
  //show({"ksdfk", 00}); // 编译错误
  show(Pig("adkfd", 20)); // 编译通过
}

class C {
public:
    string name;
    int age;
    string sex;

    C() { }
};

// C++ 11 后会自动生成一个和类的参数数量一致的构造函数
void test2(){
  B b1 = {1,2};
  b1.show();

  B b2 = {1};
  b2.show();
}

void test3()
{
    //C c = {"tyr", 25, "男"};

}

int main()
{
  test3();
  return 0;
}
