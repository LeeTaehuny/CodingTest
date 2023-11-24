#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

vector<int> adj[11];
bool visited[11][11];
bool check[11][11];
int n;
int ret = 987654321;

int dy[4] = {-1, 0, 1, 0 };
int dx[4] = {0, 1, 0, -1 };

vector<pair<int, int>> test;

int calc()
{
	int sum = 0;

	for (int i = 1; i < n - 1; i++)
	{
		for (int j = 1; j < n - 1; j++)
		{
			if (visited[i][j])
			{
				sum += adj[i][j];
				sum += adj[i][j - 1];
				sum += adj[i][j + 1];
				sum += adj[i - 1][j];
				sum += adj[i + 1][j];
			}
		}
	}

	return sum;
}

bool dfs(int y, int x)
{
	check[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (check[ny][nx]) return false;

		check[ny][nx] = true;
	}

	return true;
}

bool c()
{
	for (int i = 1; i < n - 1; i++)
	{
		for (int j = 1; j < n - 1; j++)
		{
			if (visited[i][j])
			{
				if (!dfs(i, j))
				{
					memset(check, false, sizeof(check));
					return false;
				}
			}
		}
	}
	memset(check, false, sizeof(check));
	return true;
}

void go(int h, int cnt)
{
	if (cnt > 3) return;
	if (!c()) return;

	if (cnt == 3)
	{
		ret = min(ret, calc());
		return;
	}


	for (int i = h; i < n - 1; i++)
	{
		for (int j = 1; j < n - 1; j++)
		{
			if (visited[i][j] || visited[i - 1][j] || visited[i + 1][j] || visited[i][j - 1] || visited[i][j + 1])
			{
				continue;
			}
			visited[i][j] = 1;
			go(i, cnt + 1);
			visited[i][j] = 0;
		}
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int temp;
			cin >> temp;
			adj[i].push_back(temp);
		}
	}

	go(1, 0);

	cout << ret;
}