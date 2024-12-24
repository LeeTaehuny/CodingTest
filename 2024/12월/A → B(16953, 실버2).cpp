// https://www.acmicpc.net/problem/16953 : A → B, 16953 (c++) 

#include <iostream>

using namespace std;
using ll = long long;

int a, b;
ll res = 1e23;
ll def = res;

void go(ll a, ll b, ll cnt)
{
    if (a == b)
    {
        res = min(res, cnt);
        return;
    }

    if (a > b) return;

    // * 2
    go(a * 2, b, cnt + 1);
    // a + 1
    go(a * 10 + 1, b, cnt + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b;

    go(a, b, 0);

    if (res == def)
    {
        cout << -1;
    }
    else
    {
        cout << res + 1;
    }
}