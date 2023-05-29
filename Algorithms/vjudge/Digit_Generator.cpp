#include <iostream>

int main()
{
    int N;
    std::cin >> N;

    while (N-- > 0)
    {
        int number;
        std::cin >> number;

        int cnt = 0;
        int tar = -1;

        for (int n = number; n > 0; n/=10)
            cnt++;


        for (int i = std::max(0, number - cnt*9); i < number; i++)
        {
            int sum = i;
            int n = i;

            while (n > 0)
            {
                sum += n %10;
                n /= 10;
            }

            if (sum == number)
            {
                tar = i;
                break;
            }
        }

        if (tar > 0)
        {
            std::cout << tar << std::endl;
        } else
        {
            std::cout << 0 << std::endl;
        }

    }

    return 0;
}
