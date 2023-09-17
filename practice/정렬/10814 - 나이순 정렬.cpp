/** https://www.acmicpc.net/problem/10814 [정렬] */

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<pair<int, string>> v;

bool cmp(pair<int, string> a, pair<int, string> b)
{
	if (a.first == b.first)
	{
		return false;
	}

	return a.first < b.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num;
		string name;
		cin >> num >> name;

		v.push_back(make_pair(num, name));
	}

	stable_sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; i++)
	{
		cout << v[i].first << " " << v[i].second << "\n";
	}
}