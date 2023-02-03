#include <iostream>
#include <vector>
using namespace std;

int poker_hash[14];

bool IsContinuous(vector<int> numbers)
{
    for (int i = 0; i < numbers.size(); i++)
    {
        poker_hash[numbers[i]]++;

        if (poker_hash[numbers[i]] > 1 && numbers[i] != 0)
            return false;
    }

    int nonsequence_count = 0;
    int prev_idx = INT_MIN;
    int count = 0;

    for (int i = 1; i < 14; i++)
    {
        if (poker_hash[i] == 0)
            continue;

        if (prev_idx == INT_MIN)
            prev_idx = i;

        nonsequence_count += i - prev_idx;
        prev_idx = i;
        count++;
    }

    bool is_sequence = (nonsequence_count - count + 1 - poker_hash[0]) <= 0;
    /* cout << nonsequence_count << endl;
    cout<<count<<endl;
    cout<<poker_hash[0]<<endl; */
    return is_sequence;
}

int main()
{

    return 0;
}