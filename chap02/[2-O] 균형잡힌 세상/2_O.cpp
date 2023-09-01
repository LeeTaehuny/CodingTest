#include <iostream>
#include <string>
#include <stack>
using namespace std;

string str;
stack<char> src;
stack<char> desc;

int main()
{
	while (true)
	{

		getline(cin, str);

		if (str == ".")
		{
			break;
		}

		// 입력
		for (int i = 0; i < (int)str.size(); i++)
		{
			if (str[i] == '[' || str[i] == ']' || str[i] == '(' || str[i] == ')')
			{
				src.push(str[i]);
			}
		}

		while (!src.empty())
		{
			// desc가 비어있다면? - src의 top를 넣고 src pop
			if (desc.empty())
			{
				desc.push(src.top());
				src.pop();
			}
			// desc가 비어있지 않다면
			else
			{
				if ((src.top() == '[' && desc.top() == ']') ||
					(src.top() == '(' && desc.top() == ')'))
				{
					src.pop();
					desc.pop();
				}
				else
				{
					desc.push(src.top());
					src.pop();
				}
			}
		}

		if (desc.empty())
		{
			cout << "yes" << '\n';
		}
		else
		{
			cout << "no" << '\n';
		}

		while (!desc.empty())
		{
			desc.pop();
		}
	}
}