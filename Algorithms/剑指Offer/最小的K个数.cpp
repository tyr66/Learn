#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
{
    vector<int> heap;

    if(k == 0||input.empty())
    return heap;
    if(k>=input.size())
    return input;

    heap.assign(input.begin(), input.begin() + k);
    make_heap(heap.begin(), heap.end());

    for (int i = k; i < input.size(); i++)
    {
        if (heap.front() <= input[i])
            continue;
        pop_heap(heap.begin(), heap.end());
        heap.pop_back();
        heap.push_back(input[i]);
        push_heap(heap.begin(), heap.end());
    }

    sort(heap.begin(), heap.end());

    return heap;
}

int main()
{

    return 0;
}