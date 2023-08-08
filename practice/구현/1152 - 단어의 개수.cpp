/** https://www.acmicpc.net/problem/1152 [구현, 문자열]*/

#include <iostream>
#include <string>

using namespace std;

string str;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    getline(cin, str);

    bool bIsCnt = true;
    int cnt = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            bIsCnt = true;
        }

        if (str[i] != ' ' && bIsCnt)
        {
            cnt++;
            bIsCnt = false;
        }
    }
    cout << cnt;
}