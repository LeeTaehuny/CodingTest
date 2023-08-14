/** https://www.acmicpc.net/problem/2292 [수학] */
#include <iostream>
using namespace std;

int start = 1;
int N;
int cnt = 1;
int verse = 6;

int main()
{
	cin >> N;

	while (true)
	{
		if (N == 1)
		{
			cout << cnt;
			break;
		}

		if (start + verse < N)
		{
			start += verse;
			cnt++;
			verse += 6;
		}
		else
		{
			cnt++;
			cout << cnt;
			break;
		}
	}
}