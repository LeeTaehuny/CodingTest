#include <iostream>

using namespace std;

long long A;
long long B;
long long C;

long long solution(int a, int b, int c)
{
	if (b == 0)
	{
		return 1;
	}
	else if (b % 2 == 0)
	{
		long long n = solution(a, b / 2, c);
		return n % c * n % c;
	}
	else
	{
		long long n = solution(a, (b - 1) / 2, c);
		return a % c * n % c * n % c;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B >> C;

	long long ret = solution(A, B, C);
	cout << ret;
}

// 9,223,372,036,854,775,807