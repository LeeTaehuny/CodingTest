#include <iostream>
#include <vector>
#include <cmath>
#include <string.h>
using namespace std;

vector<int> adj[52];
bool visited[52][52];

int sum;
vector<pair<int, int>> p;

int cnt;
bool flag = true;
int res;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int n, l, r;

void dfs(int y, int x)
{
	visited[y][x] = true;

	p.push_back(make_pair(y, x));
	sum += adj[y][x];
	cnt++;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n)
		{
			continue;
		}

		if (abs(adj[y][x] - adj[ny][nx]) < l || abs(adj[y][x] - adj[ny][nx]) > r)
		{
			continue;
		}

		if (visited[ny][nx])
		{
			continue;
		}

		flag = true;
		dfs(ny, nx);
	}
}

int main()
{
	cin >> n >> l >> r;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int temp;
			cin >> temp;

			adj[i].push_back(temp);
		}
	}

	while (flag)
	{
		flag = false;

		memset(visited, false, sizeof(visited));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!visited[i][j])
				{
					dfs(i, j);

					for (auto k : p)
					{
						adj[k.first][k.second] = sum / cnt;
					}
					p.clear();
					sum = 0;
					cnt = 0;
				}
			}
		}

		if (flag)
		{
			res++;
		}
	}

	cout << res;
}