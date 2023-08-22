#include <iostream>
#include <map>
using namespace std;

int N, C;

int input[1004];
map<int, int> m;

int cnt, maxNum;

int main()
{
	cin >> N >> C;

	for (int i = 0; i < N; i++)
	{
		int temp;

		cin >> temp;

		if (m.find(temp) == m.end())
		{
			m.insert(make_pair(temp, 1));
			input[i] = temp;
		}
		else
		{
			m[temp]++;
		}
	}

	for (auto it = m.begin(); it != m.end(); it++)
	{
		if (maxNum < it->second)
		{
			maxNum = it->second;
		}
	}

	while (maxNum > 0)
	{
		for (int i = 0; i < N; i++)
		{
			if (maxNum == m[input[i]])
			{
				for (int j = 0; j < maxNum; j++)
				{
					cout << input[i] << " ";
				}
			}
		}

		maxNum--;
	}
}