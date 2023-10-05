/** https://www.acmicpc.net/problem/18110 [수학, 구현, 정렬] */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int idx;
vector<int> num;
int res;

int main()
{
    cin >> n;

    if (n == 0)
    {
        cout << "0" << '\n';
        return 0;
    }


    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        num.push_back(t);
    }
    sort(num.begin(), num.end());


    float temp = static_cast<float>(n) * 0.15f;
    int tmp = static_cast<float>(n) * 0.15f;

    if (temp - static_cast<float>(tmp) >= 0.5f)
    {
        tmp++;
    }

    idx = tmp;

    for (int i = idx; i < n - idx; i++)
    {
        res += num[i];
    }

    temp = static_cast<float>(res) / static_cast<float>(n - (idx * 2));
    tmp = res / (n - (idx * 2));

    if (temp - static_cast<float>(tmp) >= 0.5f)
    {
        tmp++;
    }

    cout << tmp;

    return 0;
}