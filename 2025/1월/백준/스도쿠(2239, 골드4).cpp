// https://www.acmicpc.net/problem/2239 : 스도쿠, 2239 (c++) 

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 보드(9 x 9)
vector<vector<int>> adj(9, vector<int>(9));
// 0이 들어간 위치 (탐색 위치)
vector<pair<int, int>> pos;

// 현재 위치에서 가능한 숫자를 반환
vector<int> CheckNum(int y, int x)
{
    vector<int> v;

    bool temp[10] = { true, true, true, true, true, true, true, true, true, true };

    // 가로 체크
    for (int i = 0; i < 9; i++)
    {
       // if (adj[y][i] == 0) continue;

        temp[adj[y][i]] = false;
    }

    // 세로 체크
    for (int i = 0; i < 9; i++)
    {
       // if (adj[i][x] == 0) continue;

        temp[adj[i][x]] = false;
    }

    // 3 * 3 체크
    int startY = (y / 3) * 3;
    int startX = (x / 3) * 3;

    for (int i = startY; i < startY + 3; i++)
    {
        for (int j = startX; j < startX + 3; j++)
        {
            if (adj[i][j] == 0) continue;

            temp[adj[i][j]] = false;
        }
    }

    // temp 배열 중 true인 곳만 v에 추가
    for (int i = 1; i <= 9; i++)
    {
        if (temp[i])
        {
            v.push_back(i);
        }
    }

    return v;
}

// 스도쿠 출력
void PrintAdj() 
{
    for (int i = 0; i < 9; i++) 
    {
        for (int j = 0; j < 9; j++) 
        {
            cout << adj[i][j];
        }
        cout << '\n';
    }
}

void Go(int cnt) 
{
    if (cnt == pos.size()) 
    {
        PrintAdj();
        exit(0); 
    }

    int y = pos[cnt].first;
    int x = pos[cnt].second;

    // 현재 위치에서 올 수 있는 모든 숫자를 구하기
    vector<int> nums = CheckNum(y, x);

    for (int num : nums) 
    {
        adj[y][x] = num; // 숫자 대입
        Go(cnt + 1);     // 다음 칸으로 이동
        adj[y][x] = 0;   // 숫자 원상 복구
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 9; i++) 
    {
        string line;
        cin >> line;

        for (int j = 0; j < 9; j++)
        {
            int num = line[j] - '0';
            adj[i][j] = num;

            if (num == 0)
            {
                pos.push_back({ i, j });
            }
        }
    }

    Go(0);
}
