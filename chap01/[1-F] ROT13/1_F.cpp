#include <iostream>
#include <string>
using namespace std;

string sentence;

void ROT13(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		// 대문자인 경우
		if (s[i] >= 65 && s[i] <= 90)
		{
			if (s[i] + 13 > 90)
			{
				s[i] += -13;
			}
			else
			{
				s[i] += 13;
			}
		}
		// 소문자인 경우
		else if (s[i] >= 97 && s[i] <= 122)
		{
			if (s[i] + 13 > 122)
			{
				s[i] += -13;
			}
			else
			{
				s[i] += 13;
			}
		}
	}
	cout << s << endl;
}

int main()
{
	getline(cin, sentence);

	ROT13(sentence);
}