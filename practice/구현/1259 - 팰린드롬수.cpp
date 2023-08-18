/** https://www.acmicpc.net/problem/1259 [구현, 문자열] */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string str;
vector<char> v;

int main()
{
	while (true)
	{
		cin >> str;

		if (str == "0")
		{
			exit(0);
		}

		for (int i = 0; i < (int)str.size(); i++)
		{
			v.push_back(str[i]);
		}

		vector<char> temp = v;
		reverse(temp.begin(), temp.end());

		if (v == temp)
		{
			cout << "yes" << '\n';
		}
		else
		{
			cout << "no" << '\n';
		}

		v.clear();
		temp.clear();
	}
}