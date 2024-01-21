#include<iostream>
#include <string.h>
#include<vector>
#include <algorithm>
using namespace std;

vector<int> adj[11];
bool visited[11];
int num[11], comp[11];
int n, n2;
int result = 987654321;

pair<int, int> dfs(int u, int value)
{
	pair<int, int> ret = make_pair(1, num[u]);
	visited[u] = true;

	for (int v : adj[u])
	{
		if (comp[v] != value) continue;
		if (visited[v]) continue;

		pair<int, int> tmp = dfs(v, value);

		ret.first += tmp.first;
		ret.second += tmp.second;
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> num[i];
	}

	for (int i = 1; i <= n; i++)
	{
		cin >> n2;

		for (int j = 0; j < n2; j++)
		{
			int temp;
			cin >> temp;
			adj[i].push_back(temp);
			adj[temp].push_back(i);
		}
	}

	for (int i = 1; i < (1 << n) - 1; i++)
	{
		memset(visited, 0, sizeof(visited));
		memset(comp, 0, sizeof(comp));

		int idx1 = -1;
		int idx2 = -1;

		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				comp[j + 1] = 1;
				idx1 = j + 1;
			}
			else
			{
				idx2 = j + 1;
			}
		}

		pair<int, int> p1 = dfs(idx1, 1);
		pair<int, int> p2 = dfs(idx2, 0);

		if (p1.first + p2.first == n)
		{
			result = min(result, abs(p1.second - p2.second));
		}
	}

	if (result == 987654321)
	{
		cout << -1;
	}
	else
	{
		cout << result;
	}


}