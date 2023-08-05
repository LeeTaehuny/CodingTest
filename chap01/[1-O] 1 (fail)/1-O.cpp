#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		long long num = 1;
		int ret = 1;

		while (true)
		{
			if (num % n == 0)
			{
				cout << ret << '\n';
				break;
			}
			else
			{
				num = num * 10 + 1;
				num = num % n;

				ret++;
			}
		}
	}
}
