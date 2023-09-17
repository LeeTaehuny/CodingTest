/** https://www.acmicpc.net/problem/1676 [수학] */

#include<iostream>

using namespace std;

int n, cnt;

int main()
{
    cin >> n;

    for (int i = 0; i <= n; i += 5)
    {
        if (i == 0)
        {
            continue;
        }

        if (i % 5 == 0)
        {
            cnt++;
        }

        if (i % 25 == 0)
        {
            cnt++;
        }

        if (i % 125 == 0)
        {
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}