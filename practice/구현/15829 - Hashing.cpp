/** https://www.acmicpc.net/problem/15829 [구현, 문자열, 해싱] */

#include <iostream>

using namespace std;

int N;
long long sum, result;
int Arr[50];
int r = 31;
int m = 1234567891;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		char temp;
		cin >> temp;
		Arr[i] = temp - 96;
	}

	for (int i = 0; i < N; i++)
	{
		sum = Arr[i];

		for (int j = 0; j < i; j++)
		{
			sum = (sum * r) % m;
			sum = sum % m;
		}

		result += sum;
		result %= m;
	}

	cout << result;
}
