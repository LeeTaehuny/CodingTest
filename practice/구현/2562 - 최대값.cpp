/** https://www.acmicpc.net/problem/2562 [구현] */
#include <iostream>

using namespace std;

int Arr[9];

int main()
{
	for (int i = 0; i < 9; i++)
	{
		cin >> Arr[i];
	}

	int max = -1;
	int maxIndex = 0;

	for (int i = 0; i < 9; i++)
	{
		if (Arr[i] > max)
		{
			max = Arr[i];
			maxIndex = i;
		}
	}

	cout << max << '\n';
	cout << maxIndex + 1 << '\n';
}