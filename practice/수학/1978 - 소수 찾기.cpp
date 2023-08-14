/** https://www.acmicpc.net/problem/1978 [수학, 정수론, 소수 판정] */
#include <iostream>

using namespace std;

int N, temp, cnt;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;

		for (int j = 2; j <= temp; j++)
		{
			if (temp == j)
			{
				cnt++;
			}

			if (temp % j == 0)
			{
				break;
			}
		}
	}

	cout << cnt;
}