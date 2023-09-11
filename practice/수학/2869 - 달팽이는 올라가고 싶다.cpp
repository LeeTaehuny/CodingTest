/** https://www.acmicpc.net/problem/2869 [수학] */

#include <iostream>

using namespace std;

int up, down, h;

int main()
{
    cin >> up >> down >> h;

    if ((h - up) % (up - down) == 0)
    {
        cout << (h - up) / (up - down) + 1;
    }
    else
    {
        cout << (h - up) / (up - down) + 2;
    }

}