#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices)
{
    int min_value = INT_MAX;
    int max_value = INT_MIN;
    int max_profit = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        if (prices[i] < min_value)
        {
            max_value = min_value = prices[i];
        }
        else if (prices[i] > max_value)
        {
            max_value = prices[i];
        }

        max_profit = max(max_profit,max_value - min_value);
    }

    return max_profit;
}