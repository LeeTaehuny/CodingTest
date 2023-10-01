#include<iostream>
#include<string>
#include<string.h>
#include<vector>

using namespace std;

vector<char> op;
vector<int> num;

vector<int> v;

int n;
string temp;
int res = -987654321;


int t(int first, int second, char c)
{
	if (c == '+')
	{
		return first + second;
	}
	if (c == '-')
	{
		return first - second;
	}
	if (c == '*')
	{
		return first * second;
	}
}

int calc(int idx, int c, int cnt)
{
	if (cnt == 1)
	{
		return t(c, num[idx + 1], op[idx]);
	}
	else
	{
		return t(c, t(num[idx + 1], num[idx + 2], op[idx + 1]), op[idx]);
	}
}

void go(int idx, int cal)
{
	if (idx == num.size() - 1)
	{
		res = max(res, cal);
		return;
	}

	// 하나씩 계산
	go(idx + 1, calc(idx, cal, 1));

	if (idx + 2 < num.size())
		// 괄호 계산
		go(idx + 2, calc(idx, cal, 2));
}

int main()
{
	cin >> n;
	cin.ignore();

	getline(cin, temp);

	for (int j = 0; j < n; j++)
	{
		if (temp[j] >= '0' && temp[j] <= '9')
		{
			num.push_back(temp[j] - '0');
		}
		else
		{
			op.push_back(temp[j]);
		}
	}

	go(0, num[0]);

	cout << res;
}