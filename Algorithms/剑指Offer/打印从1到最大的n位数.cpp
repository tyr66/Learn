#include <iostream>
#include <vector>
#include <string>
using namespace std;

void print_number(vector<int>&number,int len)
{
    for (int i = 1; i <= len; i++)
    {
        cout << number[i];
    }
    cout << endl;
}
void print_number(string&str,int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        cout << (int)str[i];
    }
    cout << endl;
}


int increase_string(string&str,int n)
{
    int increament = 1;
    int idx = 0;
    while (increament != 0)
    {
        str[idx] += increament;
        increament = str[idx] / 10;
        str[idx] %= 10;
        idx++;
    }
    return max(idx,n);
}
void print_numbers_string(int n)
{
    string str(100,0);
    int place = 0;

    while (place <=n)
    {
       place = increase_string(str,place);
       if (place <= n)
           print_number(str,place);
    }
}


void print_number_recursion(vector<int>&number,int depth, int n)
{
    if (depth > n)
    {
        print_number(number,n);
        return;
    }

    for (int i = depth == 1 ? 1 : 0; i <= 9; i++)
    {
        number[depth] = i;
        print_number_recursion(number, depth + 1,n);
    }

}
void print_numbers_recursion(int n)
{
    vector<int> number;
    for (int i = 1; i <= n; i++)
    {
        number.resize(i+1);
        print_number_recursion(number,1,i);
    }
}


int main()
{
    print_numbers_recursion(0);
    return 0;
}