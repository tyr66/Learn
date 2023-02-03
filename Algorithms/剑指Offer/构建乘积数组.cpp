#include <iostream>
#include <vector>
using namespace std;

vector<int> multiply(const vector<int> &A)
{
    vector<int> res;
    vector<int> forward_multarray;
    vector<int> backward_multArray;
    int length = A.size()+2;
    res.resize(A.size());
    backward_multArray.resize(length, 1);
    forward_multarray.resize(length, 1);

    for (int i = 1; i < length; i++)
    {
        forward_multarray[i] = forward_multarray[i - 1] * A[i - 1];
        backward_multArray[length-1-i] = backward_multArray[length-i]*A[A.size()-i]; 
    }

    for(int i = 0;i<A.size();i++)
    {
        res[i] = forward_multarray[i]*backward_multArray[i+2];
    }

    return res;
}

int main()
{

    return 0;
}