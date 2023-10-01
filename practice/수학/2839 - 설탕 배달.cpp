/** https://www.acmicpc.net/problem/2839 [수학, 다이나믹 프로그래밍, 그리디 알고리즘] */

#include <iostream>
using namespace std;

int n;
int res = 987654321;
int c[5000];

void calc(int num, int cnt)
{
	if (num == 0)
	{
		if (res > cnt)
		{
			res = cnt;
		}
		return;
	}

	if (num < 0)
	{
		return;
	}

	if (c[num] <= cnt && c[num])
	{
		return;
	}
	c[num] = cnt;

	calc(num - 5, cnt + 1);
	calc(num - 3, cnt + 1);
}

int main()
{
	cin >> n;

	calc(n, 0);

	if (res == 987654321)
	{
		cout << "-1";
	}
	else
	{
		cout << res;
	}
}