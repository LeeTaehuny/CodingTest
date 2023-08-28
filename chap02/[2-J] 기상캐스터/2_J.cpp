#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int H, W;
int adj[104][104];
int visited[104][104];

string temp;

void BFS(int y, int x)
{
	visited[y][x] = 0;
	queue<int>q;
	q.push(x);

	while (!q.empty())
	{
		x = q.front();
		q.pop();

		int nx = x + 1;

		if (nx >= W || adj[y][nx] == 0)
		{
			continue;
		}

		visited[y][nx] = visited[y][x] + 1;
		q.push(nx);
	}
}

int main()
{
	memset(visited, -1, sizeof(visited));

	cin >> H >> W;

	for (int i = 0; i < H; i++)
	{
		cin >> temp;
		for (int j = 0; j < W; j++)
		{
			if (temp[j] == '.')
			{
				adj[i][j] = -1;
			}
			else
			{
				adj[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (adj[i][j] == 0)
			{
				BFS(i, j);
			}
		}
	}

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cout << visited[i][j] << " ";
		}
		cout << '\n';
	}
}