#include <iostream>
#include <vector>
using namespace std;

int N, M, cnt;
vector<int> adj[50];
bool visited[50];

void DFS(int u)
{
	if (visited[u] == true)
	{
		return;
	}

	visited[u] = true;

	if (adj[u].size() == 0 || (adj[u].size() == 1 && adj[u][0] == M))
	{
		cnt++;
	}

	for (int i = 0; i < adj[u].size(); i++)
	{
		if (adj[u][i] != M)
			DFS(adj[u][i]);
	}
}

int main()
{
	int root = -1;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;

		if (temp == -1)
		{
			root = i;
		}
		else
		{
			adj[temp].push_back(i);
		}
	}

	cin >> M;

	if (M == root)
	{
		cout << 0;
	}
	else
	{
		DFS(root);
		cout << cnt;
	}
}