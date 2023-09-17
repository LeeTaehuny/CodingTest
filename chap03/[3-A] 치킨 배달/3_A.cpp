#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> adj[52];

vector<pair<int, int>> ch;
vector<pair<int, int>> house;

int kk = 987654321;
int n, m;

int calc(vector<pair<int, int>>b)
{
	int sum = 0;

	for (int i = 0; i < house.size(); i++)
	{
		int mn = 987654321;
		for (int j = 0; j < b.size(); j++)
		{
			int num = abs(house[i].first - b[j].first) + abs(house[i].second - b[j].second);
			if (mn > num)
			{
				mn = num;
			}
		}
		sum += mn;
	}

	return sum;
}

void go(int idx, vector<pair<int, int>> b)
{
	if (b.size() == m)
	{
		int res = calc(b);

		kk = min(res, kk);
		return;
	}

	for (int i = idx + 1; i < ch.size(); i++)
	{
		b.push_back(ch[i]);
		go(i, b);
		b.pop_back();
	}
	return;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int temp;
			cin >> temp;

			adj[i].push_back(temp);

			if (temp == 1)
			{
				house.push_back({ i, j });
			}
			else if (temp == 2)
			{
				ch.push_back({ i, j });
			}
		}
	}
	vector<pair<int, int>> v;
	go(-1, v);

	cout << kk << endl;
}