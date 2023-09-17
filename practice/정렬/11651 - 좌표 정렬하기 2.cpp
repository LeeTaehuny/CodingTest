/** https://www.acmicpc.net/problem/11651 [정렬] */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int, int>> v;
int n;

bool cmp(pair<int, int>a, pair<int, int>b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }

    if (a.second < b.second)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        v.push_back({ x,y });
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " " << v[i].second << '\n';
    }

    return 0;
}