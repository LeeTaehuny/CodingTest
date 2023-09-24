/** https://www.acmicpc.net/problem/1920 [자료구조, 정렬, 이분 탐색] */

#include<iostream>
#include<unordered_map>
using namespace std;

unordered_map<int, int> src;
int desc[100000];

int n, m;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		src[temp]++;
	}

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> desc[i];
	}

	for (int i = 0; i < m; i++)
	{
		if (src[desc[i]])
		{
			cout << "1" << '\n';
		}
		else
		{
			cout << "0" << '\n';
		}
	}
}