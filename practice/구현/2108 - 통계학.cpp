/** https://www.acmicpc.net/problem/2108 [구현, 수학, 정렬] */

#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int n;
map<int, int> m;

float sum;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		if (m.find(temp) != m.end())
		{
			m[temp]++;
		}
		else
		{
			m.insert(make_pair(temp, 1));
		}
	}

	// 평균
	for (auto it : m)
	{
		sum += it.first * it.second;
	}

	float temp = (sum / n) - (static_cast<int>(sum) / n);

	if ((sum / n) >= 0 && abs(temp) >= 0.5f)
	{
		cout << (static_cast<int>(sum) / n) + 1 << '\n';
	}
	else if ((sum / n) < 0 && abs(temp) >= 0.5f)
	{
		cout << (static_cast<int>(sum) / n) - 1 << '\n';
	}
	else
	{
		cout << (static_cast<int>(sum) / n) << '\n';
	}

	// 중앙값
	int cnt = 0;
	int idx = n / 2;

	for (auto it : m)
	{
		for (int i = 0; i < it.second; i++)
		{
			if (cnt == idx)
			{
				cout << it.first << '\n';
			}
			cnt++;
		}
	}

	// 최빈값
	int mn = -1;

	for (auto it : m)
	{
		if (mn < it.second)
		{
			mn = it.second;
		}
	}

	vector<int> v;

	for (auto it : m)
	{
		if (it.second == mn)
		{
			v.push_back(it.first);
		}
	}

	sort(v.begin(), v.end());

	if (v.size() >= 2)
		cout << v[1] << '\n';
	else
		cout << v[0] << '\n';

	v.clear();

	// 범위
	for (auto it : m)
	{
		v.push_back(it.first);
	}

	sort(v.begin(), v.end());

	cout << v.back() - v.front() << '\n';
}
