#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M, N, K;

int cnt;

int sx, sy, ex, ey;
int sum;
vector<int> s;

int adj[104][104];
int visited[104][104];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void DFS(int y, int x)
{
	visited[y][x] = 1;
	sum++;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= N || nx >= M || adj[ny][nx] == 1)
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
	cin >> N >> M >> K;

	for (int i = 0; i < K; i++)
	{
		cin >> sx >> sy >> ex >> ey;

		for (int y = sy; y < ey; y++)
		{
			for (int x = sx; x < ex; x++)
			{
				adj[y][x] = 1;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (adj[i][j] != 1 && !visited[i][j])
			{
				cnt++;
				sum = 0;
				DFS(i, j);
				s.push_back(sum);
			}
		}
	}
	sort(s.begin(), s.end());

	cout << cnt << '\n';
	for (int i : s)
	{
		cout << i << " ";
	}
}