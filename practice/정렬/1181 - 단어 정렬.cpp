/** https://www.acmicpc.net/problem/1181 [문자열, 정렬] */

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int n;
vector<string> v;
map<string, int> m;

bool cmp(string s1, string s2)
{
	if (s1.length() < s2.length())
		return true;
	if (s1.length() == s2.length())
		return s1.compare(s2) < 0;

	return false;
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;

		m[temp];
	}

	for (auto it : m)
	{
		v.push_back(it.first);
	}

	sort(v.begin(), v.end(), cmp);

	for (string str : v)
	{
		cout << str << '\n';
	}
}