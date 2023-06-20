#include <iostream>
//
//const long long m = 1000;

int main()
{
  int *p = new int();
  long long m = 1000000000;
  //不允许narrowing conversion
  //int n =int{m}; 
  
  // 强制类型转换,允许narrowing conversion 但是不允许将整型转换为指针这一类的操作
  int n = static_cast<int>(m);

  // 位级别的转换
  int * t = reinterpret_cast<int*>(10439);

  std::cout << n << std::endl;


  delete p;

  return 0;
}
