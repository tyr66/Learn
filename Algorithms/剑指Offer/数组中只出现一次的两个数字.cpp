#include <iostream>
#include <vector>
using namespace std;

vector<int> FindNumsAppearOnce(vector<int> &array)
{
    vector<int> res;
    int mask = 0;
    for (int i = 0; i < array.size(); i++)
        mask ^= array[i];
    int max_mask = 0x70000000;

    while ((max_mask & mask) == 0)
        max_mask = max_mask >> 1;
    
    int fir_val = 0;
    int sec_val = 0;
    for(int i = 0;i<array.size();i++)
    {
        if(array[i]&max_mask)
        {
            sec_val^=array[i];
        }else
        {
            fir_val^=array[i];
        }
    }

    res.push_back(fir_val);
    res.push_back(sec_val);
    return res;
}

int main()
{

    return 0;
}