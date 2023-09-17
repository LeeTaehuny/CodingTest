/** https://www.acmicpc.net/problem/2751 [정렬] */

#include<iostream>
#include<map>
using namespace std;

map<int, int> m;
int n;

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        m[k];
    }

    for (auto it : m)
    {
        cout << it.first << '\n';
    }
    return 0;
}