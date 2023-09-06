/** https://www.acmicpc.net/problem/2609 [수학, 정수론, 유클리드 호제법] */

#include <iostream>

using namespace std;

int N, M;
int Dmax;
int Mmin;

int main()
{
	cin >> N >> M;

	// 최대 공약수
	for (int i = 1; i < N + 1; i++)
	{
		if (N % i == 0 && M % i == 0)
		{
			Dmax = i;
		}
	}

	int c_N = N;
	int c_M = M;

	// 최소 공배수
	while (true)
	{
		if (N == M)
		{
			Mmin = N;
			break;
		}

		if (N > M)
		{
			M += c_M;
		}
		else
		{
			N += c_N;
		}
	}

	cout << Dmax << '\n';
	cout << Mmin << '\n';
}