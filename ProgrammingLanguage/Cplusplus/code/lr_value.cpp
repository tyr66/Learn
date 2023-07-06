#include <iostream>
#include <string>
using namespace std;

void show(string &s)
{
  cout << "L_VALUE " << s << endl;
}

void show(string&& s)
{
  cout << "R_VALUE " << s << endl;
}

int main()
{
  string a = "tyr";
  string b = "-1997";

  string s = a + b;

  show(a);
  show(b);
  show(a + b);

  return 0;
}
