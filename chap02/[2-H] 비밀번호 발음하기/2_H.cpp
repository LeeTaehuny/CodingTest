#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isContain = false;
bool isContinue = false;
bool isSame = true;

int JaCnt = 0;
int MoCnt = 0;

bool isMo = false;

string Mo = "eoaiu";
string str;

int main()
{
	while (true)
	{
		cin >> str;

		if (str == "end")
		{
			exit(0);
		}

		for (int i = 0; i < Mo.size(); i++)
		{
			if (find(str.begin(), str.end(), Mo[i]) != str.end())
			{
				isContain = true;
				break;
			}

		}

		for (int i = 0; i < str.size(); i++)
		{
			isMo = false;

			for (int j = 0; j < Mo.size(); j++)
			{
				if (str[i] == Mo[j])
				{
					isMo = true;
					break;
				}
			}

			if (isMo)
			{
				MoCnt++;
				JaCnt = 0;
			}
			else
			{
				JaCnt++;
				MoCnt = 0;
			}

			if (MoCnt >= 3 || JaCnt >= 3)
			{
				isContinue = true;
				break;
			}
		}

		for (int i = 0; i < str.size() - 1; i++)
		{
			isSame = true;
			if (str[i] == str[i + 1])
			{
				if (str[i] == 'e' || str[i] == 'o')
				{
					isSame = true;
				}
				else
				{
					isSame = false;
					break;
				}
			}
		}

		if (isContain && !isContinue && isSame)
		{
			cout << "<" << str << "> is acceptable." << endl;
		}
		else
		{
			cout << "<" << str << "> is not acceptable." << endl;
		}

		JaCnt = 0;
		MoCnt = 0;

		isSame = true;
		isContain = false;
		isContinue = false;
	}
}