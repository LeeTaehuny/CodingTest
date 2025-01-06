// https://www.acmicpc.net/problem/1916 : 최소비용 구하기, 1916 (c++) 

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 시작지, 목적지, 비용
vector<pair<int, int>> adj[1002];
// 최소 비용 갱신용 배열
int visited[1002];

int n, m;

struct Comp
{
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2)
    {
        return p1.second > p2.second;
    }
};

void go(int start, int end)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pq;

    // start 지점과 연결된 모든 도착지 저장하기
    for (const pair<int, int>& p : adj[start])
    {
        // 방문 처리
        visited[p.first] = min(visited[p.first], p.second);

        // 큐에 추가
        pq.push(p);
    }

    // 큐가 전부 빌 때까지 반복
    while (!pq.empty())
    {
        // 다음 노드와 거리 추출
        int next = pq.top().first;
        int distance = pq.top().second;

        // 기존 노드 삭제
        pq.pop();

        // 만약 추출된 거리가 현재 저장된 거리보다 큰 경우 건너뛰기
        if (distance > visited[next]) continue;

        // 연결된 전체 노드 탐색
        for (const pair<int, int>& p : adj[next])
        {
            // 해당 노드까지의 거리 추출
            int nextDistance = distance + p.second;

            // 만약 기존에 저장된 거리보다 더 최소 거리라면?
            if (nextDistance < visited[p.first])
            {
                // 거리 업데이트
                visited[p.first] = nextDistance;

                // 큐에 추가
                pq.push(make_pair(p.first, nextDistance));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int start, end, price;
        cin >> start >> end >> price;

        adj[start].push_back(make_pair(end, price));
    }

    fill(visited, visited + 1002, 987654321);

    int start, end;
    cin >> start >> end;

    go(start, end);

    cout << visited[end];
}
