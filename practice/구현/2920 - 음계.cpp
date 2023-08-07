/** https://www.acmicpc.net/problem/2920 [구현] */

#include <iostream>
#include <string>

using namespace std;

string num;
string asc = "12345678";
string desc = "87654321";

int main()
{
    for (int i = 0; i < 8; i++)
    {
        string temp;
        cin >> temp;
        num += temp;
    }

    if (num.compare(asc) == 0)
    {
        cout << "ascending";
    }
    else if (num.compare(desc) == 0)
    {
        cout << "descending";
    }
    else
    {
        cout << "mixed";
    }
}