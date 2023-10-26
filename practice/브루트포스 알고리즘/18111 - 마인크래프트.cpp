/** https://www.acmicpc.net/problem/2798 [브루트포스 알고리즘, 구현] */

#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int n, k, b;
map<int, int> m;
int mx;
int mn = 987654321;

int main()
{
	cin >> n >> k >> b;

	// 맵에 입력하기
	// -> 높이별 칸 수
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			int temp;
			cin >> temp;

			mx = max(temp, mx);
			mn = min(temp, mn);

			if (m.find(temp) != m.end())
			{
				m[temp]++;
			}
			else
			{
				m.insert(make_pair(temp, 1));
			}
		}
	}

	// 시간을 비교하기 위한 타이머
	int time = 987654321;
	// 높이를 비교하기 위한 변수
	int height = -1;

	// 가장 낮은 칸부터 높은 칸까지 반복하며 최소 시간 구해보기
	for (int h = 0; h <= mx; h++)
	{
		// 지울 칸 수
		int deleteBlock = 0;
		// 채울 칸 수
		int insertBlock = 0;
		// 사용 가능한 블록 수
		int useableBlock = 0;
		// 총 소요 시간
		int tempTime = 0;

		// 매 칸 반복하며 지울칸 추가
		for (auto it : m)
		{
			// 기준 높이보다 높다면?
			if (h < it.first)
			{
				// 높은 만큼 지울 칸 수에 추가합니다.
				deleteBlock += (it.first - h) * it.second;
			}
		}

		// 매 칸 반복하며 채울칸 추가
		for (auto it : m)
		{
			// 기준 높이보다 낮다면?
			if (h > it.first)
			{
				// 낮은 만큼 채울 칸 수에 추가합니다.
				insertBlock += (h - it.first) * it.second;
			}
		}

		// 인벤토리 블록 수를 계산합니다.
		useableBlock = b + deleteBlock - insertBlock;

		// 인벤토리에 남은 블록이 음수라면?
		if (useableBlock < 0)
		{
			// 오버해서 채운 것이므로 종료합니다.
			continue;
		}

		// 채울 칸, 지울 칸을 전부 구했으므로 소요 시간을 계산합니다.
		tempTime = (insertBlock * 1) + (deleteBlock * 2);

		// 소요시간을 바탕으로 최소 시간을 구해줍니다.
		if (time >= tempTime)
		{
			time = tempTime;

			// 현재 높이를 바탕으로 최대 높이를 구해줍니다.
			if (height < h)
			{
				height = h;
			}
		}
	}

	cout << time << " " << height;
	
}