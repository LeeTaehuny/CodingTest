#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int r, c;
vector<int> adj[21];
bool alphbet[27];

int mx = -1;
int cnt;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void dfs(int y, int x, int cnt)
{
	if (cnt > mx)
	{
		mx = cnt;
	}

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
		if (alphbet[adj[ny][nx] - 'A']) continue;

		alphbet[adj[ny][nx] - 'A'] = true;
		dfs(ny, nx, cnt + 1);
		alphbet[adj[ny][nx] - 'A'] = false;
	}
}

int main()
{
	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		string temp;
		cin >> temp;

		for (int j = 0; j < c; j++)
		{
			adj[i].push_back(temp[j]);
		}
	}

	alphbet[adj[0][0] - 'A'] = true;
	dfs(0, 0, 1);
	cout << mx;
}