#include <iostream>
#include <string>
#include <vector>
using namespace std;

int char_hash[128];

int FirstNotRepeatingChar(string str)
{
    for (int i = 0; i < str.size(); i++)
    {
        char_hash[str[i]]++;
    }

    for (int i = 0; i < str.size(); i++)
    {

        if (char_hash[str[i]] == 1)
            return i;
    }

    return -1;
}

int main()
{
    return 0;
}