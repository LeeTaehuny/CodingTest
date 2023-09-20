#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

vector<char> adj[1002];
int visited[1002][1002];
int FireV[1002][1002];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int r, c;
pair<int, int> pos;
vector<pair<int, int>> firePos;

int res = 0;

string temp;

void bfsF()
{
	queue<pair<int, int>> q;

	for (int i = 0; i < firePos.size(); i++)
	{
		FireV[firePos[i].first][firePos[i].second] = 1;
		q.push(make_pair(firePos[i].first, firePos[i].second));
	}


	while (!q.empty())
	{
		pair<int, int> p = q.front();
		q.pop();

		// 이동여부 확인
		for (int i = 0; i < 4; i++)
		{
			int ny = p.first + dy[i];
			int nx = p.second + dx[i];

			if (ny < 0 || nx < 0 || ny >= r || nx >= c || FireV[ny][nx])
			{
				continue;
			}

			if (adj[ny][nx] == '#' || adj[ny][nx] == 'F')
			{
				continue;
			}

			FireV[ny][nx] = FireV[p.first][p.second] + 1;
			q.push(make_pair(ny, nx));

		}

	}
}

void bfsJ(int y, int x)
{
	visited[pos.first][pos.second] = 1;

	if (y == 0 || x == 0 || y == r - 1 || x == c - 1)
	{
		res = visited[y][x];
		return;
	}

	queue<pair<int, int>> q;
	q.push(make_pair(y, x));

	while (!q.empty())
	{
		y = q.front().first;
		x = q.front().second;
		q.pop();


		// 이동여부 확인
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx])
			{
				continue;
			}

			if (adj[ny][nx] == '#' || adj[ny][nx] == 'F')
			{
				continue;
			}

			if (FireV[ny][nx] != 0 && FireV[ny][nx] <= visited[y][x] + 1)
			{
				continue;
			}

			visited[ny][nx] = visited[y][x] + 1;

			if (ny == 0 || nx == 0 || ny == r - 1 || nx == c - 1)
			{
				res = visited[ny][nx];
				return;
			}

			// 이동
			q.push(make_pair(ny, nx));
		}

	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c;
	cin.ignore();

	// 맵 입력
	for (int i = 0; i < r; i++)
	{
		getline(cin, temp);

		for (int j = 0; j < c; j++)
		{
			if (temp[j] == 'J')
			{
				// 출발지 저장
				pos = make_pair(i, j);
			}

			if (temp[j] == 'F')
			{
				// 불난 위치 저장
				firePos.push_back(make_pair(i, j));
			}

			adj[i].push_back(temp[j]);
		}
	}

	bfsF();
	bfsJ(pos.first, pos.second);

	if (res == 0)
	{
		cout << "IMPOSSIBLE";
	}
	else
	{
		cout << res;
	}
}