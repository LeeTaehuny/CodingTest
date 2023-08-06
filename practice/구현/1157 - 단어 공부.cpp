/** https://www.acmicpc.net/problem/1157 [구현, 문자열] */

#include <iostream>
#include <string>

using namespace std;

string Word;
int num[26];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> Word;

	for (int i = 0; i < Word.size(); i++)
	{
		if (Word[i] >= 'A' && Word[i] <= 'Z')
		{
			num[Word[i] - 'A']++;
		}
		else if (Word[i] >= 'a' && Word[i] <= 'z')
		{
			num[Word[i] - 'a']++;
		}
	}

	int max = -1;
	int cnt = 0;
	int maxIndex = 0;

	for (int i = 0; i < sizeof(num) / sizeof(int); i++)
	{
		if (num[i] > max)
		{
			max = num[i];
			maxIndex = i;
		}
	}

	for (int i = 0; i < sizeof(num) / sizeof(int); i++)
	{
		if (num[i] == max)
		{
			cnt++;
		}
	}

	char a = maxIndex + 'A';

	if (cnt >= 2)
	{
		cout << "?" << endl;
	}
	else
	{
		cout << a << endl;
	}
}
