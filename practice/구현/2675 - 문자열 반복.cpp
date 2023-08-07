/** https://www.acmicpc.net/problem/2675 [구현, 문자열] */

#include <iostream>
#include <string>

using namespace std;

int N;
int R;
string S;
string solve;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> R;
		cin >> S;

		for (int j = 0; j < S.size(); j++)
		{
			for (int k = 0; k < R; k++)
			{
				solve = solve + S[j];
			}
		}

		cout << solve << '\n';

		solve = "";
	}
}