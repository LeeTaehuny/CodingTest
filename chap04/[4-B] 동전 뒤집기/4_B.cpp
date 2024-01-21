#include<iostream>
#include<string>
#include<vector>
using namespace std;

int n;
int arr[22];
int ret = 987654321;

void go(int here)
{
	if (here == n + 1)
	{
		int cnt = 0;
		for (int i = 1; i <= (1 << n - 1); i *= 2)
		{
			int sum = 0;
			for (int j = 1; j <= n; j++)
			{
				if (arr[j] & i)
				{
					sum ++;
				}
			}
			cnt += min(sum, n - sum);
		}
		ret = min(ret, cnt);
		return;
	}

	go(here + 1);
	arr[here] ^= (1 << n) - 1;
	go(here + 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		string temp;
		cin >> temp;

		for (int j = 0; j < n; j++)
		{
			if (temp[j] == 'T')
			{
				arr[i] |= (1 << j);
			}
		}
	}

	go(1);

	cout << ret;
}