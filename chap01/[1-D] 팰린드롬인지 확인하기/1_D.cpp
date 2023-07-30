#include <iostream>
using namespace std;

string word;

bool SameWord()
{
	cin >> word;

	int i = 0;
	int j = word.length() - 1;

	bool same = true;

	while (same)
	{
		if (j <= i)
		{
			return true;
		}

		if (word[i] == word[j])
		{
			i++;
			j--;
		}
		else
		{
			same = false;
		}
	}
	return false;
}

int main()
{
	cout << SameWord() << endl;
}