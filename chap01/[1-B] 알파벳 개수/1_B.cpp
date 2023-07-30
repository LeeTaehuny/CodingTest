#include <iostream>
using namespace std;

int Alphabet[26];

int main()
{
	string word;

	cin >> word;

	for (int i = 0; i < word.length(); i++)
	{
		int a = word[i];
		Alphabet[a - 97]++;
	}

	for (int i : Alphabet)
	{
		cout << i << " ";
	}
}