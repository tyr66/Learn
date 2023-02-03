#include <iostream>
#include <vector>
using namespace std;

bool verify(vector<int> seq, int lo, int hi)
{
    if (lo >= hi)
        return true;

    int mid = lo;

    for (int i = lo; i <= hi; i++)
    {
        if (seq[i] >= seq[hi])
        {
            mid = i;
            break;
        }
    }

    for (int i = mid; i < hi; i++)
    {
        if (seq[i] < seq[hi])
            return false;
    }

    return verify(seq, lo, mid - 1) && verify(seq, mid, hi - 1);
}

bool VerifySquenceOfBST(vector<int> sequence)
{

    if (sequence.empty())
        return false;

    return verify(sequence, 0, sequence.size() - 1);
}

int main()
{

    return 0;
}