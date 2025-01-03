// https://www.acmicpc.net/problem/11660 : 구간 합 구하기 5, 11660 (c++) 

#include <iostream>

using namespace std;

long long pSum[1025][1025]; // 누적합 배열
int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력 처리
    cin >> n >> m;

    // 누적합 배열 초기화
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int num;
            cin >> num;

            // 2차원 누적합 계산
            pSum[i][j] = num + pSum[i - 1][j] + pSum[i][j - 1] - pSum[i - 1][j - 1];
        }
    }

    // 쿼리 처리
    for (int i = 0; i < m; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        // 구간 합 계산
        long long result = pSum[x2][y2] - pSum[x1 - 1][y2] - pSum[x2][y1 - 1] + pSum[x1 - 1][y1 - 1];

        cout << result << '\n';
    }

    return 0;
}
