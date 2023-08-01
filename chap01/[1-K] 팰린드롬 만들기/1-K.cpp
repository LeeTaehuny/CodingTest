#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
string temp;
map<char, int> m;

string leftStr;
string midStr;

string solve;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> temp;

    int length = temp.size();

    for (int i = 0; i < length; i++)
    {
        auto it = m.find(temp[i]);

        if (it != m.end())
        {
            it->second++;
        }
        else
        {
            m.insert(make_pair(temp[i], 1));
        }
    }

    int Odd = 0;
    int cnt = 0;

    if (temp.size() == 2 && temp[0] != temp[1])
    {
        cout << "I'm Sorry Hansoo" << '\n';
        return 0;
    }

    for (auto it = m.begin(); it != m.end(); it++)
    {
        if (it->second % 2 == 1)
        {
            midStr = it->first;
            Odd++;
        }

        for (int i = 0; i < it->second / 2; i++)
        {
            leftStr = leftStr + it->first;
            cnt++;
        }
    }

    if (Odd >= 2)
    {
        cout << "I'm Sorry Hansoo" << '\n';
        return 0;
    }

    solve = leftStr + midStr;
    reverse(leftStr.begin(), leftStr.end());

    solve = solve + leftStr;

    cout << solve;
}