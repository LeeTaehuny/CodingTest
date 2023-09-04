#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int N, M, cnt, wallCnt;
int maxCnt = -1;
int adj[10][10];
bool visited[10][10];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

vector<pair<int, int>> area;

void DFS(int y, int x)
{
	cnt++;
	visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx])
		{
			continue;
		}

		if (adj[ny][nx] == 0)
		{
			DFS(ny, nx);
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
			cin >> adj[i][j];

			if (adj[i][j] == 0)
			{
				area.push_back(make_pair(i, j));
			}
			else if (adj[i][j] == 1)
			{
				wallCnt++;
			}
		}
	}

	for (int i = 0; i < (int)area.size() - 2; i++)
	{
		for (int j = i + 1; j < (int)area.size() - 1; j++)
		{
			for (int k = j + 1; k < (int)area.size(); k++)
			{
				adj[area[i].first][area[i].second] = 1;
				adj[area[j].first][area[j].second] = 1;
				adj[area[k].first][area[k].second] = 1;

				for (int y = 0; y < N; y++)
				{
					for (int x = 0; x < M; x++)
					{
						if (adj[y][x] == 2 && !visited[y][x])
						{
							DFS(y, x);
						}
					}
				}

				if ((N * M) - (wallCnt + 3) - cnt > maxCnt)
				{
					maxCnt = (N * M) - (wallCnt + 3) - cnt;
				}

				adj[area[i].first][area[i].second] = 0;
				adj[area[j].first][area[j].second] = 0;
				adj[area[k].first][area[k].second] = 0;

				memset(visited, false, sizeof(visited));
				cnt = 0;
			}
		}
	}

	cout << maxCnt;
}