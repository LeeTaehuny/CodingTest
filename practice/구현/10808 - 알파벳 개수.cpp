/** https://www.acmicpc.net/problem/10809 [구현, 문자열] */

// memset : string.h 헤더파일 추가하기.. (컴파일 오류 1회)

#include <iostream>
#include <string.h>

using namespace std;

string Word;
int num[26];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(num, -1, 26 * sizeof(int));

	cin >> Word;

	for (int i = 0; i < Word.size(); i++)
	{
		if (num[Word[i] - 'a'] == -1)
		{
			num[Word[i] - 'a'] = i;
		}
	}

	for (int i : num)
	{
		cout << i << " ";
	}
}
