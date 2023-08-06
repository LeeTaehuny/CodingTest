/** https://www.acmicpc.net/problem/11720 [구현, 수학, 문자열] */

// #include <conio.h> 헤더 인식 불가 (컴파일 오류 1번..)
// "1d%"로 문자 1개만 입력받을 수 있음.

#include <iostream>
#include <stdio.h>
using namespace std;

int N;

int main()
{
	cin >> N;

	int sum = 0;

	for (int i = 0; i < N; i++)
	{
		int num = 0;
		scanf("%1d", &num);
		sum = sum + num;
	}
	cout << sum;
}
