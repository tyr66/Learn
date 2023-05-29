#include <iostream>
#include <string>
#include <cstring>
#include <ctype.h>

char keys[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main()
{
    std::string str;
    int key_len = std::strlen(keys);
    
    while (std::getline(std::cin, str))
    {
        if (str.empty())
            continue;

        bool find_key = false;

        for (char c : str)
        {
            find_key = false;

            for (int i = 0; i < key_len; i++)
            {
                if (c == keys[i])
                {
                    std::cout << keys[i - 1];
                    find_key = true;
                    break;
                }
            }

            if (!find_key)
                std::cout << c;
        }

        std::cout << std::endl;
    }
    return 0;
}
