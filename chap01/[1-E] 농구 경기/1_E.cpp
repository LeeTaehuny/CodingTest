#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;
string FirstName[150];
int num[150];
bool success = false;

int main()
{
	cin >> N;

	string temp;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;

		FirstName[i] = temp[0];
	}

	sort(&FirstName[0], &FirstName[N]);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (FirstName[i] == FirstName[j])
			{
				num[i]++;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (num[i] == 5)
		{
			cout << FirstName[i];

			success = true;
		}
	}

	if (!success)
	{
		cout << "PREDAJA" << endl;
	}
}