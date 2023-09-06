#include <iostream>
#include <stack>
using namespace std;

int N;
stack<int> s;
int arr[1000004];
int res[1000004];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	for (int i = N - 1; i >= 0; i--)
	{
		while (!s.empty() && s.top() <= arr[i])
		{
			s.pop();
		}

		if (s.empty())
		{
			res[i] = -1;
		}
		else
		{
			res[i] = s.top();
		}

		s.push(arr[i]);
	}

	for (int i = 0; i < N; i++)
		cout << res[i] << " ";
}