/** https://www.acmicpc.net/problem/8958 [구현, 문자열] */

#include <iostream>

using namespace std;

int N;
string S;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> S;
		
		int cnt = 0;
		int sum = 0;

		for (int j = 0; j < S.size(); j++)
		{
			if (S[j] == 'O')
			{
				cnt++;
				sum = sum + cnt;
			}
			else
			{
				cnt = 0;
			}
		}
		cout << sum << '\n';
	}
}
