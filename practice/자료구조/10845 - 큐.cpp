/** https://www.acmicpc.net/problem/10845 [자료구조, 큐] */

#include<iostream>
#include<string>
#include<queue>
using namespace std;

queue<int> que;

void push(int x)
{
	que.push(x);
}

int front()
{
	if (que.size() == 0)
	{
		return -1;
	}

	return que.front();
}

int back()
{
	if (que.size() == 0)
	{
		return -1;
	}

	return que.back();
}

int size()
{
	return que.size();
}

int empty()
{
	if (que.empty())
	{
		return 1;
	}

	return 0;
}

int pop()
{
	if (que.size() == 0)
	{
		return -1;
	}
	int temp = que.front();
	que.pop();
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