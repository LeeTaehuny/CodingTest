/** https://www.acmicpc.net/problem/4153 [기하학, 수학, 피타고라스 정리] */
#include <iostream>
#include <algorithm>
using namespace std;

int Arr[3];

int main()
{

	while (true)
	{
		cin >> Arr[0] >> Arr[1] >> Arr[2];

		if (!Arr[0] && !Arr[1] && !Arr[2])
			break;
		sort(&Arr[0], &Arr[3]);
		if (Arr[2] * Arr[2] == Arr[1] * Arr[1] + Arr[0] * Arr[0])
		{
			cout << "right" << '\n';
		}
		else
		{
			cout << "wrong" << '\n';
		}
	}
}