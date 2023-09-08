/** https://www.acmicpc.net/problem/2775 [수학, 구현, DP] */
#include <iostream>
using namespace std;

int arr[16][16];
int T, K, N;

int main()
{
	for (int i = 1; i < 16; i++)
	{
		for (int j = 1; j < 16; j++)
		{
			if (i == 1)
			{
				arr[i][j] = j;
			}
			else if (j == 1)
			{
				arr[i][j] = 1;
			}
			else
			{
				arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
			}
		}
	}

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> K;
		cin >> N;

		cout << arr[K + 1][N] << endl;
	}
}