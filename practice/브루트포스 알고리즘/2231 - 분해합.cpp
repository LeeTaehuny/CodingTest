/** https://www.acmicpc.net/problem/2231 [부르트포스 알고리즘] */

#include <iostream>

using namespace std;

int N, sum;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int d = 1;
	for (int i = 1; i <= N; i++)
	{
		sum = i;

		for (int j = 0; j < 6; j++)
		{
			if (j == 0)
			{
				sum = sum + (i % d);
				sum = sum + ((i / d) % 10);
			}

			if (i >= d && j != 0)
			{
				sum = sum + ((i / d) % 10);
			}

			d *= 10;
		}

		if (sum == N)
		{
			cout << i;
			exit(0);
		}
		d = 10;
	}
	cout << "0";
}