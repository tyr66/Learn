#include <iostream>

void hello();
int factorial(int n);

int main()
{
  hello();
  std::cout << factorial(5) << std::endl;
  std::cout << "main is done" << std::endl;
}
