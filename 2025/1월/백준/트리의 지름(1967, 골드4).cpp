// https://www.acmicpc.net/problem/1967 : 트리의 지름, 1967 (c++) 

#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;

int n;
vector<pair<int, int>> adj[10002];
vector<pair<int, int>> rAdj[10002];
int visited[10002];

vector<pair<int, int>> leafs;
int mx = -1;

void DFS(int u)
{
    // 연결된 노드가 없는 경우 (자식 노드가 없다 = 리프 노드)
    // => 리프 노드 모음에 추가
    if (adj[u].size() == 0)
    {
        // (해당 노드까지의 거리, 노드 번호)
        leafs.push_back(make_pair(visited[u], u));
    }

    // 연결된 노드 모두 탐색
    for (const pair<int, int>& v : adj[u])
    {
        // 만약 해당 노드가 방문처리된 노드인 경우 건너뛰기
        if (visited[v.first] != -1) continue;

        // 거리 저장
        visited[v.first] = visited[u] + v.second;
        // 연결된 노드로 이동
        DFS(v.first);
    }
}

void Dijkstra(int start)
{
    // 우선순위 큐 생성
    priority_queue<pair<int, int>> pq;
    // 첫 노드 삽입
    pq.push(make_pair(0, start));
    visited[start] = 0;

    while (!pq.empty())
    {
        // 현재 정보 추출
        int curr = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        mx = max(mx, dist);

        // 더 작은 거리가 존재하는 경우 건너뛰기
        if (visited[curr] != -1 && visited[curr] < dist) continue;

        // 연결된 모든 노드 체크
        for (const pair<int, int>& v : adj[curr])
        {
            // 다음 위치와 거리 계산
            int next = v.first;
            int nDist = visited[curr] + v.second;

            // 만약 기존에 저장된 거리가 더 적은 경우 건너뛰기
            if (visited[next] != -1 && visited[next] < nDist) continue;

            // 갱신
            visited[next] = nDist;
            // 큐에 추가
            pq.push(make_pair(nDist, next));
        }

        for (const pair<int, int>& v : rAdj[curr])
        {
            // 다음 위치와 거리 계산
            int next = v.first;
            int nDist = visited[curr] + v.second;

            // 만약 기존에 저장된 거리가 더 적은 경우 건너뛰기
            if (visited[next] != -1 && visited[next] < nDist) continue;

            // 갱신
            visited[next] = nDist;
            // 큐에 추가
            pq.push(make_pair(nDist, next));
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    // 간선 입력받기
    for (int i = 0; i < n - 1; i++)
    {
        int p, c, dist;
        cin >> p >> c >> dist;

        // 시작점 - 종료점, 거리 쌍으로 저장
        adj[p].push_back(make_pair(c, dist));

        // 종료점 - 시작점, 거리 쌍으로 저장
        rAdj[c].push_back(make_pair(p, dist));
    }

    memset(visited, -1, sizeof(visited));

    // 생각에는 1번(루트)부터 bfs를 통해 전체 길이를 계산
    // -> 이후 가장 거리가 긴 노드 2개를 찾아 공유하는 부모 노드를 찾기
    // -> 해당 부모 노드까지의 2개의 노드 거리 계산

    visited[1] = 0;
    DFS(1);

    // 리프 노드 정렬
    sort(leafs.rbegin(), leafs.rend());

    memset(visited, -1, sizeof(visited));

    // 가장 긴 노드의 최단거리 계산 (다익스트라)
    Dijkstra(leafs[0].second);

    cout << mx;
}
