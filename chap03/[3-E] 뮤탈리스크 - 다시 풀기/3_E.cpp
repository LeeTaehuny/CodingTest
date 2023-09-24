#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int n;
int res = 987654321;
vector<int> scv(3);
int HP[61][61][61];

void go(int hp1, int hp2, int hp3, int cnt)
{
	if (hp1 <= 0 && hp2 <= 0 && hp3 <= 0)
	{
		if (res > cnt)
		{
			res = cnt;
		}
		return;
	}

	if (hp1 <= 0) hp1 = 0;
	if (hp2 <= 0) hp2 = 0;
	if (hp3 <= 0) hp3 = 0;

	if (HP[hp1][hp2][hp3] <= cnt && HP[hp1][hp2][hp3] != 0) return;

	HP[hp1][hp2][hp3] = cnt;

	go(hp1 - 9, hp2 - 3, hp3 - 1, cnt + 1);
	go(hp1 - 9, hp3 - 3, hp2 - 1, cnt + 1);

	go(hp2 - 9, hp1 - 3, hp3 - 1, cnt + 1);
	go(hp2 - 9, hp3 - 3, hp1 - 1, cnt + 1);

	go(hp3 - 9, hp1 - 3, hp2 - 1, cnt + 1);
	go(hp3 - 9, hp2 - 3, hp1 - 1, cnt + 1);

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> scv[i];
	}

	go(scv[0], scv[1], scv[2], 0);

	cout << res;
}