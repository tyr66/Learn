#include <iostream>
#include <string>

using namespace std;

class Test{
public:
  Test() = default;
  Test(const Test&a){}
  //Test& operator=(const Test&a) = delete;
  Test& operator=(const Test&a) {cout << "operator = " << endl; return *this;}
  Test(Test&&a){cout << "move construct " << endl;}
  Test& operator=(const Test&&a) = delete;
  ~Test(){}
};

Test get_test()
{
  return Test();
}

int main()
{
  // Test t,t1;
  // t = t1;
  Test t2;
  t2 = get_test();
  return 0;
}
