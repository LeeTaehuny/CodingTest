/** https://www.acmicpc.net/problem/10828 [자료구조, 스택, 구현] */

#include<iostream>
#include<string>
#include<stack>
using namespace std;

stack<int> stk;

void push(int x)
{
	stk.push(x);
}

int top()
{
	if (stk.size() == 0)
	{
		return -1;
	}

	return stk.top();
}

int size()
{
	return stk.size();
}

int empty()
{
	if (stk.empty())
	{
		return 1;
	}

	return 0;
}

int pop()
{
	if (stk.size() == 0)
	{
		return -1;
	}
	int temp = stk.top();
	stk.pop();
	return temp;
}

int n;

int main()
{
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++)
	{
		string temp;

		getline(cin, temp);

		int it = temp.find(" ");

		string a = temp.substr(0, it);
		int b = atoi(temp.substr(it + 1).c_str());

		if (a == "push")
		{
			push(b);
		}
		else if (a == "pop")
		{
			cout << pop() << '\n';
		}
		else if (a == "size")
		{
			cout << size() << '\n';
		}
		else if (a == "empty")
		{
			cout << empty() << '\n';
		}
		else if (a == "top")
		{
			cout << top() << '\n';
		}
	}
}