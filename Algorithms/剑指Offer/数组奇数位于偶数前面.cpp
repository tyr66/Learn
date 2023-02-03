#include <iostream>
#include <vector>
using namespace std;

vector<int> reOrderArray(vector<int> &array)
{
    int even_count = 0;

    for (int i = 0; i < array.size(); i++)
    {
        if (array[i] % 2 == 0)
            even_count++;
        else
        {
            for(int j = i-1;j>=i-even_count;j--)
            {
                swap(array[j],array[j+1]);
            }
        }
    }

    return array;
}

int main()
{

    return 0;
}