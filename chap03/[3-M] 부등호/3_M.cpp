#include<iostream>
#include<string>
#include<string.h>
#include<vector>
using namespace std;

int n;
string op[9];
int num[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
bool visited[10];
vector<int> temp;

bool isEnd = false;

void dfsF(int v, int oIdx)
{
	if (temp.size() == n + 1)
	{
		for (int i : temp)
		{
			cout << i << "";
		}
		cout << endl;
		isEnd = true;
		return;
	}

	visited[v] = true;

	for (int i = 0; i < 10; i++)
	{
		if (isEnd)
		{
			return;
		}

		if (visited[i] == true) continue;

		if (op[oIdx] == ">" && num[v] < num[i]) continue;
		if (op[oIdx] == "<" && num[v] > num[i]) continue;

		temp.push_back(num[i]);
		dfsF(i, oIdx + 1);
		temp.pop_back();
		visited[i] = false;
	}
}

void dfsE(int v, int oIdx)
{
	if (temp.size() == n + 1)
	{

		for (int i : temp)
		{
			cout << i << "";
		}
		cout << endl;
		isEnd = true;
		return;
	}

	visited[v] = true;

	for (int i = 9; i >= 0; i--)
	{
		if (isEnd)
		{
			return;
		}

		if (visited[i] == true) continue;

		if (op[oIdx] == ">" && num[v] < num[i]) continue;
		if (op[oIdx] == "<" && num[v] > num[i]) continue;

		temp.push_back(num[i]);
		dfsE(i, oIdx + 1);
		temp.pop_back();
		visited[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> op[i];
	}

	for (int i = 9; i >= 0; i--)
	{
		if (isEnd)
		{
			continue;
		}
		temp.push_back(num[i]);
		visited[i] = true;
		dfsE(i, 0);
		memset(visited, false, sizeof(visited));
		temp.clear();
	}

	isEnd = false;

	for (int i = 0; i < 10; i++)
	{
		if (isEnd)
		{
			continue;
		}
		temp.push_back(num[i]);
		visited[i] = true;
		dfsF(i, 0);
		memset(visited, false, sizeof(visited));
		temp.clear();
	}
}