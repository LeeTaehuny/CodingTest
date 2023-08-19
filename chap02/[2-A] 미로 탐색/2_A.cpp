#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

int N, M;

int adj[104][104];
int visited[104][104];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void BFS(int sy, int sx)
{
	visited[sy][sx] = 1;
	queue<pair<int, int>> q;
	q.push(make_pair(sy, sx));

	while (q.size())
	{
		int y = q.front().first;
		int x = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M || adj[ny][nx] == 0)
			{
				continue;
			}

			if (visited[ny][nx] != 0)
			{
				continue;
			}

			visited[ny][nx] = visited[y][x] + 1;
			q.push(make_pair(ny, nx));
		}
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf_s("%1d", &adj[i][j]);
		}
	}

	BFS(0, 0);

	cout << visited[N - 1][M - 1];
}