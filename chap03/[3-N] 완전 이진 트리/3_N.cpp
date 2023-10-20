#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int n;
int num[20000];
vector<int> ret[14];

void bTree(int min, int depth, int max)
{
	if (min > max) return;
	if (min == max)
	{
		ret[depth].push_back(num[min]);
		return;
	}

	int mid = (min + max) / 2;
	ret[depth].push_back(num[mid]);
	bTree(min, depth + 1, mid - 1);
	bTree(mid + 1, depth + 1, max);
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	int end = (int)pow(2, n) - 1;
	for (int i = 0; i < end; i++) 
	{
		cin >> num[i];
	}

	bTree(0, 1, end);

	for (int i = 1; i <= n; i++) 
	{
		for (int j : ret[i]) 
		{
			cout << j << " ";
		}
		cout << "\n";
	}

}