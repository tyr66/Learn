#include <iostream>
#include <string>
#include <string.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_set<string> uset;

string rotateX(string&str)
{
    string res = str;
    res[0] = str[1];
    res[1] = str[5];
    res[5] = str[4];
    res[4] = str[0];
    return res;
}

string rotateY(string&str)
{
    string res = str;
    res[4] = str[3];
    res[3] = str[1];
    res[1] = str[2];
    res[2] = str[4];
    return res;
}

bool judge(string&str, string&tar)
{
    if (str == tar)
        return true;

    if (uset.find(str) != uset.end())
        return false;

    uset.insert(str);
    // 进行旋转
    string rx = rotateX(str);
    string ry = rotateY(str);

    return judge(rx, tar) || judge(ry, tar);
}

int main()
{
    string input;

    while (cin >> input)
    {
        string origin = input.substr(0, 6);
        string tar = input.substr(6, 6);

        if (judge(origin, tar))
            printf("TRUE\n");
        else 
            printf("FALSE\n");

        uset.clear();
    }


    return 0;
}
