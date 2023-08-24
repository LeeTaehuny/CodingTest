#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
string str;
vector<string> v;

bool cmp(string a, string b)
{
	if (a.length() < b.length())
		return true;
	if (a.length() == b.length())
		return a.compare(b) < 0;

	return false;
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> str;
		string temp = "";

		for (int j = 0; j < (int)str.size(); j++)
		{
			if (str[j] >= '0' && str[j] <= '9')
			{
				if (temp != "")
				{
					temp = temp + str[j];
				}
				else
				{
					temp = str[j];
				}
			}
			else
			{
				if (temp == "")
				{
					continue;
				}

				v.push_back(temp);
				temp = "";
			}
		}

		if (temp != "")
		{
			v.push_back(temp);
		}
	}

	for (int i = 0; i < (int)v.size(); i++)
	{
		string temp = v[i];

		while (true)
		{
			if (!temp.empty() && temp.front() == '0')
			{
				temp.erase(temp.begin());
			}
			else
			{
				if (!temp.empty())
				{
					v[i] = temp;
					break;
				}
				else
				{
					v[i] = "0";
					break;
				}
			}
		}
	}

	sort(v.begin(), v.end(), cmp);

	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << '\n';
	}
}