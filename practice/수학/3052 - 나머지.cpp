/** https://www.acmicpc.net/problem/3052 [사칙연산, 수학] */

#include <iostream>
#include <map>

using namespace std;

map<int, int> Rem;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 10; i++)
	{
		int num = 0;
		cin >> num;

		Rem.insert(make_pair(num % 42, 0));
	}

	cout << Rem.size();
}
