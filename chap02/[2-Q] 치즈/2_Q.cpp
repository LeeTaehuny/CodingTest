#include <iostream>
#include <string.h>

using namespace std;

int Y, X, cnt;
int adj[104][104];
bool visited[104][104];
bool moveAble[104][104];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int k[100];


void DFS(int y, int x)
{
	visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= Y || nx >= X || visited[ny][nx])
		{
			continue;
		}

		if (adj[ny][nx] == 1)
		{
			moveAble[ny][nx] = false;
			continue;
		}
		else
		{
			DFS(ny, nx);
		}

	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> Y >> X;

	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			cin >> adj[i][j];

			if (adj[i][j] == 1)
			{
				k[0]++;
				moveAble[i][j] = true;
			}
		}
	}

	int idx = 1;

	while (true)
	{
		DFS(0, 0);

		for (int i = 0; i < Y; i++)
		{
			for (int j = 0; j < X; j++)
			{
				if (moveAble[i][j] == false)
				{
					adj[i][j] = 0;
				}
			}
		}

		for (int i = 0; i < Y; i++)
		{
			for (int j = 0; j < X; j++)
			{
				if (adj[i][j] == 1)
				{
					cnt++;
				}
			}
		}

		k[idx] = cnt;

		if (cnt == 0)
		{
			break;
		}

		idx++;
		cnt = 0;
		memset(visited, false, sizeof(visited));
	}

	cout << idx << '\n';
	cout << k[idx - 1] << '\n';
}