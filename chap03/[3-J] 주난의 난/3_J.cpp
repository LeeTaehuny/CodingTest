#include<iostream>
#include<string>
#include<string.h>
#include<vector>
using namespace std;

int n, k, startx, starty, destx, desty;
int cnt;
vector<char> adj[301];
bool visited[301][301];
vector<pair<int, int>> v;

bool run = true;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void dfs(int y, int x)
{
	visited[y][x] = true;

	if (y == desty - 1 && x == destx - 1)
	{
		run = false;
	}

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= k) continue;
		if (adj[ny][nx] == '1')
		{
			visited[ny][nx] = true;
			v.push_back(make_pair(ny, nx));
			continue;
		}
		if (visited[ny][nx]) continue;

		visited[ny][nx] = true;
		dfs(ny, nx);
	}
}

int main()
{
	cin >> n >> k;
	cin >> starty >> startx >> desty >> destx;

	for (int i = 0; i < n; i++)
	{
		string temp;

		cin >> temp;

		for (int j = 0; j < k; j++)
		{
			adj[i].push_back(temp[j]);
		}
	}

	while (run)
	{
		cnt++;
		dfs(starty - 1, startx - 1);

		for (auto i : v)
		{
			adj[i.first][i.second] = '0';
		}
		
		memset(visited, false, sizeof(visited));
		v.clear();
	}

	cout << cnt;
}