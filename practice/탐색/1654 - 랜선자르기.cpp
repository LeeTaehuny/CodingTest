/** https://www.acmicpc.net/problem/1654 [이분탐색, 매개변수 탐색] */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, k;
vector<long long> v;

int main()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	long long s = 1;
	long long e = v[n - 1];
	long long mid;

	while (true)
	{
		int cnt = 0;

		mid = (s + e) / 2;

		for (int i = 0; i < n; i++)
		{
			cnt += v[i] / mid;
		}

		if (s > e)
		{
			break;
		}

		if (cnt >= k)
		{
			s = mid + 1;
		}
		else if (cnt < k)
		{
			e = mid - 1;
		}
	}

	cout << mid;
}