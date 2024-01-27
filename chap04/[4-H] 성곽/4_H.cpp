#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
using namespace std;

vector<int> adj[53];
vector<int> s;
vector<int> v[2503];
int visited[53][53];
int visited2[53][53];

int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };

int n, m;

// 방 개수
int num;
// 최대
int mx = -1;
// 제거 후 최대
int resMax = -1;

void bfs(int y, int x, int num1)
{
	int cnt = 0;
	visited[y][x] = num1;
	cnt++;
	queue<pair<int, int>> q;

	q.push({ y, x });

	while (!q.empty())
	{
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (visited[ny][nx]) continue;
			if (adj[y][x] & (1 << i)) continue;

			visited[ny][nx] = num1;
			cnt++;
			q.push({ ny, nx });
		}
	}
	s.push_back(cnt);
	mx = max(cnt, mx);
}

void dfs(int y, int x)
{
	visited2[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (visited2[ny][nx]) continue;
		if (visited[ny][nx] != visited[y][x])
		{
			if (find(v[visited[y][x]].begin(), v[visited[y][x]].end(), visited[ny][nx]) == v[visited[y][x]].end())
				v[visited[y][x]].push_back(visited[ny][nx]);
			continue;
		}

		dfs(ny, nx);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n;
	s.push_back(0);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int temp;
			cin >> temp;
			adj[i].push_back(temp);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visited[i][j] == 0)
			{
				bfs(i, j, num + 1);
				num++;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visited2[i][j] == 0)
			{
				dfs(i, j);
			}
		}
	}

	for (int i = 0; i < 2503; i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			resMax = max(resMax, s[i] + s[v[i][j]]);
		}
	}

	cout << num << '\n';
	cout << mx << '\n';
	cout << resMax << '\n';
}