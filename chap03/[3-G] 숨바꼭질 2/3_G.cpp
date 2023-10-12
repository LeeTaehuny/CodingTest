#include<iostream>
#include<queue>
using namespace std;

int n, k;
int dx[3] = { -1, 1, 2 };
int visited[100001];
int cnt[100001];

void bfs(int pos)
{
    visited[pos] = 1;
    cnt[pos] = 1;
    queue<int> q;
    q.push(pos);

    while (!q.empty())
    {
        pos = q.front();
        q.pop();

        for (int i = 0; i < 3; i++)
        {
            int np = 0;

            if (i == 2) np = pos * dx[i];
            else np = pos + dx[i];

            if (np < 0 || np >= 100001) continue;
            if (!visited[np])
            {
                q.push(np);
                visited[np] = visited[pos] + 1;
                cnt[np] += cnt[pos];
            }
            else if (visited[np] == visited[pos] + 1)
            {
                cnt[np] += cnt[pos];
            }
        }
    }
}

int main()
{
    cin >> n >> k;
    bfs(n);

    if (n == k)
    {
        cout << 0 << endl;
        cout << 1 << endl;
    }
    else
    {
        cout << visited[k] - 1 << endl;
        cout << cnt[k] << endl;
    }

    return 0;
}