#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point
{
    int x;
    int y;
};

bool compare(Point&a, Point&b)
{
    if (a.x == b.x)
        return a.y > b.y;
    return a.x < b.x;
}

bool compare_reverse(Point&a, Point&b)
{
    if (a.x == b.x)
        return a.y > b.y;
    return a.x > b.x;
}

int main()
{
    freopen("output.txt", "w", stdout);
    vector<Point> points;
    vector<Point> reverse_points;
    int T;
    cin >> T;

    while (T-- > 0)
    {
        int N;
        cin >> N;
        points.clear();
        reverse_points.clear();

        for (int i = 0, x, y; i < N; i++) {
            cin >> x >> y;
            points.push_back({x, y});
            reverse_points.push_back({x, y});
        }

        sort(points.begin(), points.end(), compare);
        sort(reverse_points.begin(), reverse_points.end(), compare_reverse);

        int left_x = points[0].x;
        int right_x = reverse_points[0].x;
        bool res = true;

        for (int i = 0; i <= N / 2; i++)
        {
            if (points[i].y != reverse_points[i].y || (points[i].x - left_x != right_x - reverse_points[i].x)) {
                res = false;
                break;
            }

            left_x = points[i].x;
            right_x = reverse_points[i].x;
        }

        if (res)
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
        
    }
    
    return 0;
}