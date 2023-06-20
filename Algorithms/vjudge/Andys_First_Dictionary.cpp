#include <iostream>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <string>
#include <set>

using namespace std;

int main()
{
  char c;
  string str;
  string line;
  set<string> wordSet;

  while (getline(cin, line))
  {
    for(int i = 0; i < line.size(); i++) {
      if (isalpha(line[i])) {
        str += tolower(line[i]);
      } else {
        if (str.size() > 0)
          wordSet.insert(str);
        str.clear();
      }
    }

    if (str.size() > 0) {
      wordSet.insert(str);
      str.clear();
    }
  }

  for (auto it = wordSet.begin(); it != wordSet.end(); it++)
    cout << *it << endl;

  return 0;
}
