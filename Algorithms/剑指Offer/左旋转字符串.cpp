#include <iostream>
#include <string>
using namespace std;

void flip(string&str,int lo,int hi)
{
    while(lo<hi)
    {
        swap(str[lo++],str[hi--]);
    }
}

string LeftRotateString(string str, int n)
{
    if(str.empty()||n ==0)
    return str;

    n = n%str.size();
    flip(str,0,n-1);
    flip(str,n,str.size()-1);
    flip(str,0,str.size()-1);

    return str;
}