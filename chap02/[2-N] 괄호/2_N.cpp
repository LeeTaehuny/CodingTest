#include <iostream>
#include <string>
#include <stack>
using namespace std;

int N;

string str;
stack<char> s;
stack<char> k;


int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> str;

		for (int j = 0; j < (int)str.size(); j++)
		{
			s.push(str[j]);
		}

		while (!s.empty())
		{
			if (k.size() == 0)
			{
				k.push(s.top());
				s.pop();
			}
			else
			{
				if (s.top() != k.top())
				{
					if ((s.top() == ')' && k.top() == '('))
					{
						k.push(s.top());
						s.pop();
					}
					else
					{
						s.pop();
						k.pop();
					}
				}
				else
				{
					k.push(s.top());
					s.pop();
				}
			}
		}

		if (k.size() == 0)
		{
			cout << "YES" << '\n';
		}
		else
		{
			cout << "NO" << '\n';
		}

		while (!k.empty())
		{
			k.pop();
		}
	}
}