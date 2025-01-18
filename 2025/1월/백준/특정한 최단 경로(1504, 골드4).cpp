// https://www.acmicpc.net/problem/1504 : 특정한 최단 경로, 1504 (c++) 

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int n, e;
int m1, m2;

// 연결된 간선 및 거리 저장용 벡터
vector<pair<int, int>> adj[802];
// 거리 저장용 배열
int visited[4][802];

void Go(int cnt, int start)
{
    // 거리, 노드 저장용 우선순위 큐
    priority_queue<pair<int, int>> pq;

    // 시작 지점 넣기 & 방문 처리
    pq.push(make_pair(0, start));
    visited[cnt][start] = 0;

    // 큐가 전부 빌 때까지 순회
    while (!pq.empty())
    {
        // 가장 우선시 되는 노드 추출
        int curr = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        // 만약 해당 노드에 대한 거리가 이미 저장된 거리보다 큰 경우 (-1 제외) 건너뛰기
        if (visited[cnt][curr] != -1 && visited[cnt][curr] < dist) continue;

        // 연결된 모든 노드 순회
        for (const pair<int, int>& n : adj[curr])
        {
            int next = n.first;
            int nDist = visited[cnt][curr] + n.second;

            // 만약 이미 저장된 값보다 nDist가 작은 경우라면? (-1 제외)
            if (visited[cnt][next] == -1 || visited[cnt][next] > nDist)
            {
                // 거리 갱신
                visited[cnt][next] = nDist;
                // 큐에 추가
                pq.push(make_pair(nDist, next));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> e;

    for (int i = 0; i < e; i++)
    {
        int a, b, distance;
        cin >> a >> b >> distance;

        // a와 연결된 지점 b와, 그 사이의 거리 저장 (양방향)
        adj[a].push_back(make_pair(b, distance));
        adj[b].push_back(make_pair(a, distance));
    }

    // 중간에 들려야 하는 정점 입력받기
    cin >> m1 >> m2;

    // visited 배열 초기화
    memset(visited, -1, sizeof(visited));

    // 1번부터 N번까지 m1, m2를 거쳐야 함
    // * 1 - m1 - m2 - N
    // * 1 - m2 - m1 - N

    // -> 1번부터 m1까지의 거리(0), 1번부터 m2까지의 거리(1)
    // -> n번부터 m1까지의 거리(2), n번부터 m2까지의 거리(3)
    // -> m1부터 m2까지의 거리(4)를 구해서 최소 연산 진행하기
    Go(0, 1);
    Go(1, n);
    Go(2, m1);
    Go(3, m2);

    // 1 - m1 - m2 - n
    int res1 = 0;
    res1 = visited[0][m1] + visited[2][m2] + visited[3][n];

    // 1 - m2 - m1 - n
    int res2 = 0;
    res2 = visited[0][m2] + visited[3][m1] + visited[2][n];

    if (visited[0][m1] == -1 || visited[2][m2] == -1 || visited[3][n] == -1) res1 = 987654321;
    if (visited[0][m2] == -1 || visited[3][m1] == -1 || visited[2][n] == -1) res2 = 987654321;

    int res = min(res1, res2);
    if (res == 987654321)
    {
        cout << -1;
    }
    else
    {
        cout << res;
    }
}
