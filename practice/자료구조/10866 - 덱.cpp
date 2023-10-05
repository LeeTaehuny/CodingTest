/** https://www.acmicpc.net/problem/10866 [자료구조, 덱, 구현] */

#include<iostream>
#include<string>
#include<deque>
using namespace std;

deque<int> dq;

void push_front(int x)
{
	dq.push_front(x);
}

void push_back(int x)
{
	dq.push_back(x);
}

int pop_front()
{
	if (!dq.empty())
	{
		int tmp = dq.front();
		dq.pop_front();
		return tmp;
	}
	else
	{
		return -1;
	}
}

int pop_back()
{
	if (!dq.empty())
	{
		int tmp = dq.back();
		dq.pop_back();
		return tmp;
	}
	else
	{
		return -1;
	}
}


int size()
{
	return dq.size();
}

int empty()
{
	if (dq.empty())
	{
		return 1;
	}

	return 0;
}

int front()
{
	if (dq.size() == 0)
	{
		return -1;
	}

	return dq.front();
}

int back()
{
	if (dq.size() == 0)
	{
		return -1;
	}

	return dq.back();
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

		if (a == "push_front")
		{
			push_front(b);
		}
		else if (a == "push_back")
		{
			push_back(b);
		}
		else if (a == "pop_front")
		{
			cout << pop_front() << '\n';
		}
		else if (a == "pop_back")
		{
			cout << pop_back() << '\n';
		}
		else if (a == "size")
		{
			cout << size() << '\n';
		}
		else if (a == "empty")
		{
			cout << empty() << '\n';
		}
		else if (a == "front")
		{
			cout << front() << '\n';
		}
		else if (a == "back")
		{
			cout << back() << '\n';
		}
	}
}