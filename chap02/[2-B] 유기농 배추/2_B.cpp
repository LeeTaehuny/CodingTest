#include <iostream>
#include <string.h>
using namespace std;

int T, M, N, K;
int bugX, bugY;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int adj[54][54];
bool visited[54][54];

int cnt;

void DFS(int y, int x)
{
	visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (nx < 0 || ny < 0 || nx >= M, ny >= N || adj[ny][nx] == 0)
		{
			continue;
		}

		if (visited[ny][nx])
		{
			continue;
		}

		DFS(ny, nx);
	}
}

int main()
{
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> M >> N >> K;

		for (int j = 0; j < K; j++)
		{
			cin >> bugX >> bugY;

			adj[bugY][bugX] = 1;
		}

		for (int a = 0; a < N; a++)
		{
			for (int b = 0; b < M; b++)
			{
				if (adj[a][b] != 0 && visited[a][b] == false)
				{
					cnt++;
					DFS(a, b);
				}
			}
		}

		cout << cnt << '\n';

		memset(adj, 0, sizeof(adj));
		memset(visited, false, sizeof(visited));
		cnt = 0;
	}
}