/** https://www.acmicpc.net/problem/1874 [자료구조, 스택] */

#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

stack<int> s;
vector<int> v;
vector<int> temp;
vector<string> res;

int n;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	int i = 1;
	int idx = 0;
	bool exit = true;

	while (exit)
	{
		if (s.size() == n)
		{
			exit = false;
		}

		s.push(i);
		res.push_back("+");
		//cout << "+" << '\n';

		if (s.top() == v[idx])
		{
			while (!s.empty() && s.top() == v[idx])
			{
				temp.push_back(s.top());
				s.pop();
				res.push_back("-");
				//cout << "-" << '\n';
				idx++;

				if (idx > n - 1)
				{
					exit = false;
					break;
				}
			}
		}

		i++;
	}

	if (v.size() == temp.size())
	{
		for (string r : res)
		{
			cout << r << '\n';
		}
	}
	else
	{
		cout << "NO";
	}
}