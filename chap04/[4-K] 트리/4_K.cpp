#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

vector<int> adj[1001];
bool visited[1001];
int T, N, B;

int root = 0;

void dfs(int v, int prev, bool& result)
{
	visited[v] = true;

	for (int u : adj[v])
	{
		if (u == prev) continue;
		if (visited[u])
		{
			result = false;
			continue;
		}

		dfs(u, v, result);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> N;
		cin >> B;

		for (int j = 0; j < B; j++)
		{
			int num1, num2;

			cin >> num1 >> num2;
			adj[num1].push_back(num2);
			adj[num2].push_back(num1);

			if (root == 0)
			{
				root = num1;
			}
		}
		bool run = true;
		dfs(root, 0, run);
		if (run)
		{
			bool r2 = true;
			for (int k = 1; k <= N; k++)
			{
				if (!visited[k])
					r2 = false;
			}

			if (r2)
				cout << "tree" << endl;
			else
				cout << "graph" << endl;
		}
		else
		{
			cout << "graph" << endl;
		}

		// 초기화 해주기
		memset(visited, false, sizeof(visited));

		for (auto& i : adj)
		{
			i.clear();
		}
	}
	
}