#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int N, M;
vector<int> adj[10002];
bool visited[10002];

int cnt;
int mCnt = -1;

int res[10002];

void DFS(int u)
{
	visited[u] = true;

	for (int v : adj[u])
	{
		if (visited[v] == false)
		{
			cnt++;
			DFS(v);
		}
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a;
		int b;

		cin >> a >> b;

		adj[b].push_back(a);
	}

	for (int i = 0; i < N; i++)
	{
		DFS(i + 1);

		if (mCnt < cnt)
		{
			mCnt = cnt;
		}

		res[i + 1] = cnt;
		cnt = 0;
		memset(visited, false, sizeof(visited));
	}

	for (int i = 0; i < 10002; i++)
	{
		if (res[i] == mCnt)
		{
			cout << i << " ";
		}
	}
}