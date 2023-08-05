#include <iostream>
#include <string>
#include <stack>
using namespace std;


string Word[100];

int N;
bool run = true;
int cnt;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> Word[i];
		
	}

	for (int i = 0; i < N; i++)
	{
		stack<char> AB;

		for (int j = 0; j < Word[i].size(); j++)
		{
			if (AB.empty())
			{
				AB.push(Word[i][j]);
				continue;
			}

			if (AB.top() == Word[i][j])
			{
				AB.pop();
			}
			else
			{
				AB.push(Word[i][j]);
			}
		}

		if (AB.empty())
		{
			cnt++;
		}
	}


	cout << cnt;
}