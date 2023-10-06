/** https://www.acmicpc.net/problem/1966 [구현, 자료구조, 시뮬레이션, 큐] */

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n, m, idx;
int cnt;

vector<int> num;
queue<pair<int, bool>> q;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> m >> idx;

		bool run = true;

		for (int j = 0; j < m; j++)
		{
			int temp;
			cin >> temp;

			num.push_back(temp);

			if (cnt != idx)
			{
				q.push(make_pair(temp, false));
			}
			else
			{
				q.push(make_pair(temp, true));
			}

			cnt++;
		}

		cnt = 0;

		sort(num.begin(), num.end());

		while (run)
		{
			int x = num[num.size() - 1 - cnt];

			for (int j = 0; j < q.size(); j++)
			{
				if (x == q.front().first)
				{
					cnt++;

					if (q.front().second == true)
					{
						cout << cnt << '\n';
						run = false;
						break;
					}

					q.pop();
					break;
				}
				else
				{
					pair<int, bool> temp = q.front();
					q.pop();
					q.push(temp);
				}
			}
		}

		cnt = 0;

		while (!q.empty())
		{
			q.pop();
		}

		num.clear();
	}
}
