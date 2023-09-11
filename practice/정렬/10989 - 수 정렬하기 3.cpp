/** https://www.acmicpc.net/problem/10989 [정렬] */

#include <iostream>
#include <map>
using namespace std;

map<int, int> m;
int n;

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
		m[temp]++;
	}

	for (auto it : m)
	{
		for (int i = 0; i < it.second; i++)
		{
			cout << it.first << '\n';
		}
	}
}