// https://www.acmicpc.net/problem/2096 : 내려가기, 2096 (c++) 

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int n;
int adj[100002][3];

// prev
int prevArr[3];
// curr
int currArr[3];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        adj[i][0] = a;
        adj[i][1] = b;
        adj[i][2] = c;
    }

    // 0번째 위치값 초기화
    for (int i = 0; i < 3; i++)
    {
        prevArr[i] = adj[0][i];
        currArr[i] = adj[0][i];
    }

    // 최대값 누적(DP)
    for (int i = 1; i < n; i++)
    {
        // * 현재 값 갱신
        // 0번째
        currArr[0] = max(prevArr[0], prevArr[1]) + adj[i][0];
        // 1번째
        currArr[1] = max(max(prevArr[0], prevArr[1]), prevArr[2]) + adj[i][1];
        // 2번째
        currArr[2] = max(prevArr[1], prevArr[2]) + adj[i][2];

        // 이전 값으로 저장
        prevArr[0] = currArr[0];
        prevArr[1] = currArr[1];
        prevArr[2] = currArr[2];
    }

    int mx = max(currArr[0], max(currArr[1], currArr[2]));

    // 0번째 위치값 초기화
    for (int i = 0; i < 3; i++)
    {
        prevArr[i] = adj[0][i];
        currArr[i] = adj[0][i];
    }

    // 최소값 누적(DP)
    for (int i = 1; i < n; i++)
    {
        // * 현재 값 갱신
        // 0번째
        currArr[0] = min(prevArr[0], prevArr[1]) + adj[i][0];
        // 1번째
        currArr[1] = min(min(prevArr[0], prevArr[1]), prevArr[2]) + adj[i][1];
        // 2번째
        currArr[2] = min(prevArr[1], prevArr[2]) + adj[i][2];

        // 이전 값으로 저장
        prevArr[0] = currArr[0];
        prevArr[1] = currArr[1];
        prevArr[2] = currArr[2];
    }

    int mn = min(currArr[0], min(currArr[1], currArr[2]));

    cout << mx << " " << mn;
}
