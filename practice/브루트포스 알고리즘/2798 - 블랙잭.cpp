/** https://www.acmicpc.net/problem/2798 [브루트포스 알고리즘] */
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	int maxSum = -1;

	for (int i = 0; i < N - 2; i++)
	{
		for (int j = i + 1; j < N - 1; j++)
		{
			for (int k = j + 1; k < N; k++)
			{
				if (maxSum < v[i] + v[j] + v[k] && v[i] + v[j] + v[k] <= M)
				{
					maxSum = v[i] + v[j] + v[k];
				}
			}
		}
	}

	cout << maxSum;
}