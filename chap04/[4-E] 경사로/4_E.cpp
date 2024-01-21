#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

vector<int> adj[105];
bool visited[105][105];

int n, l;

int answer;

// 현재 칸 기준 앞으로 탐색 (가로)
bool checkBuildDown(int y, int x)
{
    if (x + l > n) return false;  
	int height = adj[y][x];
	for (int i = 0; i < l; i++)
	{
		// 높이가 다르다면 false 리턴
		if (adj[y][x + i] != height) return false;

		// 높이가 같은 경우 건물을 지었다고 체크
		visited[y][x + i] = true;
	} 
	return true;
}

// 세로
bool checkBuildDownHeight(int y, int x)
{
    if (y + l > n) return false;  
	int height = adj[y][x];
	for (int i = 0; i < l; i++)
	{
		if (adj[y + i][x] != height) return false;
		visited[y + i][x] = true;
	}
    return true;
}

// 현재 칸 기준 뒤로 다시 탐색 (가로)
bool checkBuildUp(int y, int x)
{
    if (x - l + 1 < 0) return false;  
	int height = adj[y][x]; 
	for (int i = 0; i < l; i++)
	{
		// 높이가 다르다면 flase 리턴
		if (adj[y][x - i] != height) return false;

		// 이미 설치된 경사로가 있으면 false 리턴
		if (visited[y][x - i]) return false;
	}

	return true;
}

// 세로
bool checkBuildUpHeight(int y, int x)
{
    if (y - l + 1 < 0) return false;  
	int height = adj[y][x];

	for (int i = 0; i < l; i++)
	{
		// 높이가 다르다면 flase 리턴
		if (adj[y - i][x] != height) return false;

		// 이미 설치된 경사로가 있으면 false 리턴
		if (visited[y - i][x]) return false;
	}

	return true;
}


void checkWidth(int y)
{
	bool ret = true;

	for (int x = 0; x < n; x++)
	{
		// 다음칸이 존재하지 않는 경우 break;
		if (x + 1 == n) break;
		// 이미 ret이 false인 경우 break;
		if (ret == false) break;

		// 해당 칸과 다음 칸이 같은 경우
		if (adj[y][x] == adj[y][x + 1])
		{
			continue;
		}
		// 해당 칸보다 다음 칸이 적은 경우
		else if (adj[y][x] > adj[y][x + 1])
		{
			// 차이가 1 이상이면 ret = false
			if (adj[y][x] - adj[y][x + 1] > 1) ret = false;

			// 해당 칸보다 뒤쪽에 경사로 설치가 불가능하다면 ret = false, 종료
			if (x + l > n - 1)
			{
				ret = false;
				break;
			}

			// 경사로 설치가 불가능하다면? ret = false
			if (!checkBuildDown(y, x + 1)) ret = false;
		}
		// 해당 칸보다 다음 칸이 높은 경우
		else if (adj[y][x] < adj[y][x + 1])
		{
			// 차이가 1 이상이면 ret = false
			if (adj[y][x + 1] - adj[y][x] > 1) ret = false;

			// 해당 칸보다 앞쪽에 경사로 설치가 불가능하다면 ret = false, 종료
			if (x - (l - 1) < 0)
			{
				ret = false;
				break;
			}

			// 경사로 설치가 불가능하다면? ret = false
			if (!checkBuildUp(y, x)) ret = false;
		}
	}

	// ret가 true인 경우에만 answer 1 증가
	if (ret)
	{
		answer++;
	}
}

void checkHeight(int x)
{
	bool ret = true;

	for (int y = 0; y < n; y++)
	{
		// 다음칸이 존재하지 않는 경우 break;
		if (y + 1 == n) break;
		// 이미 ret이 false인 경우 break;
		if (ret == false) break;

		// 해당 칸과 다음 칸이 같은 경우
		if (adj[y][x] == adj[y + 1][x])
		{
			continue;
		}
		// 해당 칸보다 다음 칸이 적은 경우
		else if (adj[y][x] > adj[y + 1][x])
		{
			// 차이가 1 이상이면 ret = false
			if (adj[y][x] - adj[y + 1][x] > 1) ret = false;

			// 해당 칸보다 뒤쪽에 경사로 설치가 불가능하다면 ret = false, 종료
			if (y + l > n - 1)
			{
				ret = false;
				break;
			}

			// 경사로 설치가 불가능하다면? ret = false
			if (!checkBuildDownHeight(y + 1, x)) ret = false;
		}
		// 해당 칸보다 다음 칸이 높은 경우
		else if (adj[y][x] < adj[y + 1][x])
		{
			// 차이가 1 이상이면 ret = false
			if (adj[y + 1][x] - adj[y][x] > 1) ret = false;

			// 해당 칸보다 앞쪽에 경사로 설치가 불가능하다면 ret = false, 종료
			if (y - (l - 1) < 0)
			{
				ret = false;
				break;
			}

			// 경사로 설치가 불가능하다면? ret = false
			if (!checkBuildUpHeight(y, x)) ret = false;
		}
	}

	// ret가 true인 경우에만 answer 1 증가
	if (ret)
	{
		answer++;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> l;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int temp;
			cin >> temp;

			adj[i].push_back(temp);
		}
	}

	for (int i = 0; i < n; i++)
	{
		memset(visited, false, sizeof(visited));
		checkWidth(i);
		memset(visited, false, sizeof(visited));
		checkHeight(i);
	}

	cout << answer;

}