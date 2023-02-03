#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int str_compare(const string& a, const string& b)
{
    for (int i = 0; i < 5; i++)
    {
        if (a[i] > b[i])
            return 1;
        else if (a[i] < b[i])
            return -1;
    }

    return 0;
}

inline int get_minute(string& a)
{
    return ((a[0] - '0') * 10 + (a[1] - '0')) * 60 + (a[3] - '0') * 10 + (a[4] - '0');
}



int findMinDifference(vector<string>& timePoints)
{

    if (timePoints.size() > 1440)
        return 0;

    sort(timePoints.begin(), timePoints.end());

    int len = timePoints.size() - 1;
    int min_value = INT_MAX;

    for (int i = 0; i < len; i++)
    {
        min_value = min(min_value, get_minute(timePoints[i + 1]) - get_minute(timePoints[i]));
    }

    if (timePoints.size() >= 2)
    {
        min_value = min(min_value, get_minute(timePoints[len]) - get_minute(timePoints[0]));
        min_value = min(min_value, 1440 - get_minute(timePoints[len]) + get_minute(timePoints[0]));
    }
    return min_value;
}


int main()
{
    vector<string> timePoints;
    timePoints.push_back("23:00");
    timePoints.push_back("01:00");
    cout<<findMinDifference(timePoints);
    return 0;
}