// https://www.acmicpc.net/problem/9465 : 스티커, 9465 (c++) 

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

vector<int> nums[2];
int DP[100002][2];
int t, n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;

        memset(DP, 0, sizeof(DP));

        // 배열 초기화
        nums[0].clear();
        nums[1].clear();

        // 입력받기
        for (int j = 0; j < 2 * n; j++)
        {
            int num;
            cin >> num;

            // 0번째 행 입력
            if (n > j)
            {
                nums[0].push_back(num);
            }
            // 1번째 행 입력
            else
            {
                nums[1].push_back(num);
            }
        }

        // 현재에서 최선인 값(상, 하)을 누적해서 구해야 함
        // * 첫 번째 위치 값 설정
        DP[0][0] = nums[0][0];
        DP[0][1] = nums[1][0];

        // 두 번째 위치부터 끝까지 반복하며 최대값을 구합니다.
        for (int j = 1; j < n; j++)
        {
            // 이전 칸의 아래 + 현재 칸 or 이전 칸의 위
            DP[j][0] = max(DP[j - 1][1] + nums[0][j], DP[j - 1][0]);
            // 이전 칸의 위 + 현재 칸 or 이전 칸의 아래
            DP[j][1] = max(DP[j - 1][0] + nums[1][j], DP[j - 1][1]);
        }

        cout << max(DP[n - 1][0], DP[n - 1][1]) << '\n';
    }
}