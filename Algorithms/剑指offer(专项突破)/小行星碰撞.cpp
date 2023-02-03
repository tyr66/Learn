#include <iostream>
#include <vector>
using namespace std;

vector<int> asteroidCollision(vector<int> &asteroids)
{
    int stack_top = -1;
    vector<int> res;

    for (int i = 0; i < asteroids.size(); i++)
    {
        if(asteroids[i]<0)
        {
            while(stack_top>=0&&asteroids[stack_top]>0&&asteroids[stack_top]<abs(asteroids[i]))
            {
                stack_top--;
            }

            if(stack_top>=0&&asteroids[stack_top]>0)
            {
                stack_top = asteroids[stack_top] == abs(asteroids[i])?stack_top-1:stack_top;
                continue;
            }
        }

        asteroids[++stack_top] = asteroids[i];
    }

    if (stack_top >= 0)
        res.assign(asteroids.begin(), asteroids.begin() + stack_top+1);

    return res;
}

int main()
{
    return 0;
}