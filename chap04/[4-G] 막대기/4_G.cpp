#include<iostream>
using namespace std;

int n;
int cnt;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//64 32 16 8 4 2 1
	cin >> n;

	// 숫자 n에 i번째 비트가 켜져있는지 확인하기.
	for (int i = 0; i < 7; i++)
	{
		// 만약 켜져있는 경우 cnt 증가
		if (n & (1 << i)) cnt++;
	}

	cout << cnt;
}