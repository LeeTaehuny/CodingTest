#include<iostream>
#include<vector>

using namespace std;

int n, h, m, a, b;
bool visited[34][34];
int ret = 987654321;

bool c()
{
	for (int i = 1; i <= n; i++)
	{
		int num = i;
		for (int j = 1; j <= h; j++)
		{
			if (visited[j][num]) num++;
			else if (visited[j][num - 1]) num--;
		}

		if (num != i) return false;
	}
	return true;
}

void go(int here, int cnt)
{
	if (cnt > 3 || cnt >= ret) return;
	if (c())
	{
		ret = min(ret, cnt);
	}

	for (int i = here; i <= h; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (visited[i][j] || visited[i][j - 1] || visited[i][j + 1]) continue;

			visited[i][j] = 1;
			go(i, cnt + 1);
			visited[i][j] = 0;
		}
	}
}

int main()
{
	cin >> n >> m >> h;

	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b;
		visited[a][b] = 1;
	}

	go(1, 0);

	if (ret > 3) cout << "-1";
	else cout << ret;
}