#include <iostream>

using namespace std;

int N, M, J;
int start = 1;
int apple;
int d;

int main()
{
	cin >> N >> M;
	cin >> J;

	while (J--)
	{
		cin >> apple;

		// 사이에 있는 경우
		if (start <= apple && start + (M - 1) >= apple)
		{
			continue;
		}
		// 오른쪽에 있는 경우
		if (start + (M - 1) < apple)
		{
			d = d + (apple - (start + (M - 1)));
			start = apple - (M - 1);
			continue;
		}
		// 왼쪽에 있는 경우
		if (start > apple)
		{
			d = d + (start - apple);
			start = apple;
		}
	}

	cout << d;
}