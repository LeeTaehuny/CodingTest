/** https://www.acmicpc.net/problem/1929 [수학, 정수론, 소수 판정, 에라토스테네스의 체] */

#include<iostream>
using namespace std;

int n, m;

int num[1000002];

int main()
{
    cin >> n >> m;

    for (int i = n; i < m + 1; i++)
    {
        num[i] = i;
    }

    num[1] = -1;

    for (int i = 2; i < m + 1; i++)
    {
        for (int j = i + i; j <= m; j += i)
        {
            num[j] = -1;
        }
    }

    for (int i = n; i < m + 1; i++)
    {
        if (num[i] == -1)
        {
            continue;
        }

        cout << num[i] << '\n';
    }
}