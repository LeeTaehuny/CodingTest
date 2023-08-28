#include <iostream>

using namespace std;

int T, N;

int cnt;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> N;

		for (int j = 5; j <= N; j *= 5)
		{
			cnt = cnt + (N / j);
		}

		cout << cnt << '\n';
		cnt = 0;
	}
}