#include <iostream>
#include <vector>
using namespace std;

int NumberOf1(int n)
{
    int mark = 0x00000001;
    int count =0;
    for(int i = 0;i<32;i++)
    {
        if(mark&n)
        count++;
        mark = mark<<1;
    }
    return count;
}

int main()
{
    int n = INT_MIN-1;
    cout<<n<<endl;
    return 0;
}