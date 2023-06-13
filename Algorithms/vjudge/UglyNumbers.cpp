#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<int> numbers;

    numbers.insert(1);
    auto it = numbers.begin();
    int cnt = 1;

    while (++cnt <= 1500)
    {
        numbers.insert(*it * 2);
        numbers.insert(*it * 3);
        numbers.insert(*it * 5);
        it++;
    }

    printf("The 1500'th ugly number is %d.\n", *it);

    return 0;
}