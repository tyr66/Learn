#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, less<int>> leftHeap;
priority_queue<int, vector<int>, greater<int>> rightHeap;

void Insert(int num)
{
    if(leftHeap.size() == rightHeap.size()){
        

        if(leftHeap.empty())
        {
            leftHeap.push(num);
            return;
        }

        if(rightHeap.top()<num)
        {
            leftHeap.push(rightHeap.top());
            rightHeap.pop();
            rightHeap.push(num);
        }else
        leftHeap.push(num);
    }else if(leftHeap.size()>rightHeap.size())
    {
        if(num<leftHeap.top())
        {
            rightHeap.push(leftHeap.top());
            leftHeap.pop();
            leftHeap.push(num);
        }else
        rightHeap.push(num);
    }
}

double GetMedian()
{
    if(leftHeap.size()>rightHeap.size())
    return leftHeap.top();

    return leftHeap.empty()?0:(leftHeap.top()+rightHeap.top())/2.0f;
}

int main()
{

    return 0;
}