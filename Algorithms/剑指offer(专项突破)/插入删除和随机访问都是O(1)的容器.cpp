#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class RandomizedSet
{
public:
    /** Initialize your data structure here. */
    RandomizedSet()
    {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if (!exist(val))
        {
            ump[val] = push_to_arr(val);
            return true;
        }

        return false;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if (exist(val))
        {
            pop_from_arr(ump[val]);
            ump[val] = -1;
            return true;
        }

        return false;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        int idx = rand()%arr.size();
        return arr[idx];
    }

private:
    inline bool exist(int val)
    {
        return !(ump.find(val) == ump.end() || ump[val]==-1);
    }

    void pop_from_arr(int idx)
    {
        ump[arr[arr.size()-1]] = idx;
        swap(arr[idx],arr[arr.size()-1]);
        arr.pop_back();
    }

    int push_to_arr(int val)
    {
        arr.push_back(val);
        return arr.size() - 1;
    }

private:
    unordered_map<int, int> ump;
    vector<int> arr;
};

int main()
{

    return 0;
}