#include <iostream>
#include <string.h>
using namespace std;

int N, cnt;

int adj[104][104];
bool visited[104][104];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int height;
int maxCnt = -1;

void DFS(int y, int x)
{
	visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= N || nx >= N || adj[ny][nx] < height)
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
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> adj[i][j];
		}
	}

	while (height <= 100)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (adj[i][j] >= height && !visited[i][j])
				{
					cnt++;
					DFS(i, j);
				}
			}
		}

		if (maxCnt < cnt)
		{
			maxCnt = cnt;
		}

		memset(visited, false, sizeof(visited));
		cnt = 0;
		height++;
	}
	cout << maxCnt;
}