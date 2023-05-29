#include <iostream>
#include <string>

char keys[128];

int main()
{
    std::string str;

    keys['A'] = 'A';
    keys['E'] = '3';
    keys['H'] = 'H';
    keys['I'] = 'I';
    keys['J'] = 'L';
    keys['L'] = 'J';
    keys['M'] = 'M';
    keys['O'] = '0';
    keys['S'] = '2';
    keys['T'] = 'T';
    keys['U'] = 'U';
    keys['V'] = 'V';
    keys['W'] = 'W';
    keys['X'] = 'X';
    keys['Y'] = 'Y';
    keys['Z'] = '5';
    keys['1'] = '1';
    keys['2'] = 'S';
    keys['3'] = 'E';
    keys['5'] = 'Z';
    keys['8'] = '8';

    while (std::getline(std::cin, str))
    {
        if (str.empty())
            continue;

        bool is_palindrome = true;

        for (int i = 0, j = str.size() - 1; i < j; i++, j--)
        {
            if (str[i] != str[j])
            {
                is_palindrome = false;
                break;
            }
        }

        bool is_mirrored = true;

        for (int i = 0, j = str.size() - 1; i <= j; i++, j--)
        {
            if ( keys[str[j]] != str[i] && (str[j] != 'O' || str[i] != 'O'))
            {
                is_mirrored = false; 
                break;
            }
        }

        if (is_palindrome && is_mirrored)
            std::cout << str << " -- is a mirrored palindrome." << std::endl;
        else if (is_palindrome)
            std::cout << str << " -- is a regular palindrome." << std::endl;
        else if (is_mirrored)
            std::cout << str << " -- is a mirrored string." << std::endl;
        else 
            std::cout << str << " -- is not a palindrome." << std::endl;

        std::cout << std::endl;

    }
    return 0;
}
