#include<iostream>
#include<string>

using namespace std;

string str;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str;

	while (!str.empty())
	{
		int pi = str.find("pi");
		int ka = str.find("ka");
		int chu = str.find("chu");

		if (pi >= 0)
		{
			str.replace(pi, 2, "--");
		}
		else if (ka >= 0)
		{
			str.replace(ka, 2, "--");
		}
		else if (chu >= 0)
		{
			str.replace(chu, 3, "---");
		}

		if (pi < 0 && ka < 0 && chu < 0) break;
	}

	bool res = true;
	for (char c : str)
	{
		if (c != '-')
		{
			res = false;
			break;
		}
	}

	if (res)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
}