#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
using namespace std;

vector<int> adj[52];
int visited[52][52];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

vector<pair<int, int>> land;

string str;
int n, m;
int dis = 0;
int res = -1;

int bfs(int y, int x)
{
	visited[y][x] = 1;
	queue<pair<int, int>> q;

	q.push({ y, x });

	while (!q.empty())
	{
		pair<int, int> p = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = p.first + dy[i];
			int nx = p.second + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] != 0)
			{
				continue;
			}

			if (adj[ny][nx] == 0)
			{
				continue;
			}

			visited[ny][nx] = visited[p.first][p.second] + 1;
			dis = visited[ny][nx];
			q.push({ ny, nx });
		}
	}

	return dis;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	cin.ignore();


	for (int i = 0; i < n; i++)
	{
		getline(cin, str);

		for (int j = 0; j < m; j++)
		{
			if (str[j] == 'W')
			{
				adj[i].push_back(0);
			}
			else if (str[j] == 'L')
			{
				adj[i].push_back(1);
				land.push_back({ i, j });
			}
		}
	}

	for (int i = 0; i < land.size(); i++)
	{
		res = max(res, bfs(land[i].first, land[i].second));
		memset(visited, 0, sizeof(visited));
	}

	cout << res - 1;
}