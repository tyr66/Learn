#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int compare(const string &a, const string &b)
{
    if (a.empty() || b.empty())
    {
        throw;
    }

    int i = 0, j = 0;

    while (i < a.size() || j < b.size())
    {
        int val_a = i < a.size() ? a[i] : a[0];
        int val_b = j < b.size() ? b[j] : b[0];

        if (val_a != val_b)
            return val_a < val_b;

        i++, j++;
    }

    return 0;
}

string PrintMinNumber(vector<int> numbers)
{
    string res;

    vector<string> strNumbers;

    for (int i = 0; i < numbers.size(); i++)
    {
        strNumbers.push_back(to_string(numbers[i]));
    }

    sort(strNumbers.begin(), strNumbers.end(),compare);


    for(int i = 0;i<strNumbers.size();i++)
    {
        res.append(strNumbers[i]);
    }

    return res;
}



int main()
{

    return 0;
}