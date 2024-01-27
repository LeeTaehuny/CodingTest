#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
int m;
int ret;

void calc(string op, int num)
{
	if (op == "add")
	{
		if (ret & (1 << num)) return;
		
		ret |= (1 << num);
	}
	else if (op == "remove")
	{
		if (!(ret & (1 << num))) return;

		ret &= ~(1 << num);
	}
	else if (op == "check")
	{
		if (ret & (1 << num))
		{
			cout << 1 << '\n';
		}
		else
		{
			cout << 0 << '\n';
		}
	}
	else if (op == "toggle")
	{
		if (ret & (1 << num))
		{
			ret &= ~(1 << num);
		}
		else
		{
			ret |= (1 << num);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m;
	cin.ignore();

	for (int i = 0; i < m; i++)
	{
		string temp;
		string subOp;
		string subNum;
		getline(cin, temp);

		if (temp.find(" ") != string::npos)
		{
			subOp = temp.substr(0, temp.find(" "));
			subNum = temp.substr(temp.find(" ") + 1);

			int num = atoi(subNum.c_str());

			calc(subOp, num - 1);
		}
		else if (temp == "all")
		{
			ret |= (1 << 20) - 1;
		}
		else if (temp == "empty")
		{
			ret = 0;
		}
	}
}