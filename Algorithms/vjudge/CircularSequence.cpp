#include <iostream>
#include <string>

int main()
{
    int N;
    std::cin >> N;
    while (N-- > 0)
    {
        std::string str;
        std::getline(std::cin, str);

        if (str.empty())
        {
            N++;
            continue;
        }

        char target_char = 'T';
        int st;

        int len = str.size();

        for (int i = 0; i < len; i++)
        {
            if (str[i] < target_char)
            {
                st = i;
                target_char = str[i];
            }
        }

        bool is_continue = str[st] == str[(st + 1) % len];
        int tar = st;

        for (int i = (st + 1) % len; i != st; i = (i + 1) % len)
        {
            if (target_char == str[i] && is_continue)
                continue;

            is_continue = false;

            if (target_char != str[i])
                continue;

            int n = (tar + 1) % len, m = (i + 1) % len;

            while (str[n] == str[m] && n != tar && m != i)
            {
                n = (n + 1) % len;
                m = (m + 1) % len;
            }

            if (str[n] > str[m])
                tar = i;
        }

        for (int i = 0; i < len; i++)
        {
            std::cout << str[(tar + i) % len];
        }

        std::cout << std::endl;
    }
    return 0;
}

