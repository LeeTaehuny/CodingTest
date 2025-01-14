// https://www.acmicpc.net/problem/13549 : 숨바꼭질 3, 13549 (c++) 

#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

#define MAX 200001

int n, k;
int DP[MAX];
int dx[3] = { -1, 1, 2 };
int dist[3] = { 1, 1, 0 };


struct Comp
{
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2)
    {
        return p1.second > p2.second;
    }
};

void Go(int node)
{
    // 현재 위치와 거리를 적재합니다.
    priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pq;

    pq.push(make_pair(node, 0));
    DP[node] = 0;

    // 큐가 빌 때까지 반복합니다.
    while (!pq.empty())
    {
        // 정보를 추출합니다.
        int cPos = pq.top().first;
        int cDist = pq.top().second;
        pq.pop();

        // 만약 추출된 해당 위치의 거리가 더 작은 값이 존재하는 경우 건너뜁니다.
        if (DP[cPos] < cDist) continue;

        // 다음 위치를 찾습니다.
        for (int i = 0; i < 3; i++)
        {
            int nPos = 0;

            if (i == 2)
            {
                nPos = cPos * dx[i];
            }
            else
            {
                nPos = cPos + dx[i];
            }

            int nDist = cDist + dist[i];

            if (nPos < MAX && nPos >= 0 && nDist < DP[nPos])
            {
                DP[nPos] = nDist;
                pq.push(make_pair(nPos, nDist));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    fill(DP, DP + MAX, 987654321);

    Go(n);

    cout << DP[k];
}
