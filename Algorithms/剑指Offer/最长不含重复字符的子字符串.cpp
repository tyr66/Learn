#include <iostream>
#include <vector>
#include <string>
#include<map>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    map<char,bool> char_map;
    int start = 0,end = 0;
    int max_length = 0;

    while(end<s.size())
    {
        if(char_map[end])
        {
            while(start<end&&char_map[end])
            {
                char_map[start] = false;
                start++;
            }
        }


        max_length = max(max_length,end-end+1);
        end++;
        char_map[end] = true;
    }
    return max_length;
}

int main()
{

    return 0;
}