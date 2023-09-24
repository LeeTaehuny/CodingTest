/** https://www.acmicpc.net/problem/1018 [브루트포스 알고리즘] */
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

char src1[8][8] =
{
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'}
};

char src2[8][8] =
{
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
};

string temp;
int n, m;
char desc[51][51];
int res = 987654321;

int main()
{
    cin >> n >> m;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        getline(cin, temp);

        for (int j = 0; j < m; j++)
        {
            desc[i][j] = temp[j];
        }
    }

    for (int i = 0; i <= n - 8; i++)
    {
        for (int j = 0; j <= m - 8; j++)
        {
            int cnt1 = 0;
            int cnt2 = 0;

            for (int a = 0; a < 8; a++)
            {
                for (int b = 0; b < 8; b++)
                {
                    if (src1[a][b] != desc[i + a][j + b])
                    {
                        cnt1++;
                    }
                }
            }

            for (int a = 0; a < 8; a++)
            {
                for (int b = 0; b < 8; b++)
                {
                    if (src2[a][b] != desc[i + a][j + b])
                    {
                        cnt2++;
                    }
                }
            }

            int tmp = min(cnt1, cnt2);
            res = min(res, tmp);
        }
    }

    cout << res;

    return 0;
}