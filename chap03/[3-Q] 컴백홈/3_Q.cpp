#include<iostream>
#include<vector>

using namespace std;

int r, c, k;
vector<char> adj[6];
bool visited[6][6];
int ret;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void go(int y, int x, int cnt)
{
	if (cnt > k) return;
	if (cnt == k && (y == 0 && x == c - 1))
	{
		ret++;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx] || adj[ny][nx] == 'T')
		{
			continue;
		}

		visited[ny][nx] = true;
		go(ny, nx, cnt + 1);
		visited[ny][nx] = false;
	}

}

int main()
{
	cin >> r >> c >> k;

	for (int i = 0; i < r; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < c; j++)
		{
			adj[i].push_back(temp[j]);
		}
	}
	
	visited[r - 1][0] = true;
	go(r - 1, 0, 1);

	cout << ret;
}