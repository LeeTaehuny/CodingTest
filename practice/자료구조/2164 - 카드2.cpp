/** https://www.acmicpc.net/problem/1920 [자료구조, 큐] */

#include<iostream>
#include<queue>
using namespace std;

int n;
queue<int> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		q.push(i + 1);
	}

	while (q.size() != 1)
	{
		q.pop();
		int temp = q.front();
		q.pop();
		q.push(temp);
	}

	cout << q.front();
}