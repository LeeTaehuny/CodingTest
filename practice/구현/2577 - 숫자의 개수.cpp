/** https://www.acmicpc.net/problem/2577 [구현, 수학, 사칙연산] */

// itoa 지원 X -> sprintf()함수 사용하기. (컴파일에러 3번..)

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int a, b, c;
char temp[1000];
int cnt[10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a;
	cin >> b;
	cin >> c;

	int mult = a * b * c;

	sprintf_s(temp, "%d", mult);

	for (int i = 0; i < (int)(sizeof(temp) / sizeof(char)); i++)
	{
		cnt[temp[i] - 48]++;
	}

	for (int i : cnt)
	{
		cout << i << '\n';
	}
}
