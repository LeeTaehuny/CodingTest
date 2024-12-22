// https://www.acmicpc.net/problem/32378 : 횃불이 키우기, 32378 (c++) 

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

vector<ll> upSize;

ll n, k, s;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k >> s;

	if (k > 36)
	{
		cout << "MEGA";
		return 0;
	}
	vector<vector<ll>> DP(n + 1, vector<ll>(k + 1, -1));

	for (int i = 1; i <= n; i++)
	{
		int temp;
		cin >> temp;

		// 사이즈 배열에 추가
		upSize.push_back(temp);
	}

	DP[0][0] = s;

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			if (i == 0)
			{
				DP[i][j] = DP[0][0];
				continue;
			}

			if (DP[i - 1][j] > 0) DP[i][j] = min(DP[i - 1][j] + upSize[i - 1], (ll)1e13);

			if (j > 0)
			{
				DP[i][j] = max(DP[i][j], min(DP[i - 1][j - 1] * 2, (ll)1e13));
			}
		}
	}

	ll mx = -1;

	for (int i = 0; i <= k; i++)
	{
		mx = max(DP[n][i], mx);
	}

	if (mx > (ll)1e11)
	{
		cout << "MEGA";
	}
	else if (mx < 1)
	{
		cout << -1;
	}
	else cout << mx;
}
