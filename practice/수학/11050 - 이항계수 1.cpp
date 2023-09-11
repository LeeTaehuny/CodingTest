/** https://www.acmicpc.net/problem/11050 [수학, 구현, 조합론] */

#include <iostream>
using namespace std;

int N, K;

int main()
{
	cin >> N >> K;

	int tempT = 1;
	int tempB = 1;

	for (int i = 0; i < K; i++)
	{
		tempT *= N--;

		tempB *= i + 1;
	}

	cout << tempT / tempB;
}