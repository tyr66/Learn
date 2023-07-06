#include <iostream>
#include <memory>

using namespace std;

int main()
{
  unique_ptr<int> p = std::make_unique<int>(2);
  unique_ptr<int> p1 = std::make_unique<int>(3);
  // unique_ptr<int> p2 = p; // 会报错

  p1 = p; // 会报错
  return 0;
}
