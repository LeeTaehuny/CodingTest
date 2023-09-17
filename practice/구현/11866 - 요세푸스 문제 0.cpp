/** https://www.acmicpc.net/problem/11866 [구현, 자료구조, 큐] */

#include<iostream>
#include<queue>
using namespace std;

queue<int> q;
int n, k;
int cnt = 1;
int temp;

int main()
{
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        q.push(i + 1);
    }

    cout << "<";

    while (!q.empty())
    {
        temp = q.front();

        q.pop();

        if (cnt != k)
        {
            q.push(temp);
        }
        else
        {
            if (q.empty())
            {
                cout << temp;
                break;
            }
            cout << temp << ", ";
            cnt = 0;
        }

        cnt++;
    }

    cout << ">";
    return 0;
}
