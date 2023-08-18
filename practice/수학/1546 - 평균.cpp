/** https://www.acmicpc.net/problem/1546 [수학, 사칙연산] */

#include <iostream>

using namespace std;

float Arr[1000];
float N, sum;


int main()
{
	cin >> N;

	float max = -1;
	int maxIdx = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> Arr[i];

		if (max < Arr[i])
		{
			max = Arr[i];
			maxIdx = i;
		}
	}

	for (int i = 0; i < N; i++)
	{
		Arr[i] = Arr[i] / max * 100;
		sum += Arr[i];
	}

	cout << (sum / N);
}