/** 
[ 링크 ] https://school.programmers.co.kr/learn/courses/30/lessons/154540

[ 풀이 방법 ]

0. 방문 처리 배열 및 이동 관련 배열 선언
1. maps의 사이즈를 계산해 y, x로 2중 for문 순회
2. 순회하며 모든 (y, x)위치에 대해 dfs 실행 (방문했던 위치 or 'X'인 경우 패스)
3. 모든 위치를 체크하며 연결되어 있는만큼 sum 누적
4. sum이 0이 아니면 answer 배열에 삽입후 sum 초기화
5. answer 배열의 크기가 0이면 -1 삽입
   answer 배열의 크기가 존재한다면 sort() 함수를 이용해 정렬

*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int y_length;
int x_length;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int sum;
bool visited[104][104];

void dfs(vector<string> m, int y, int x)
{
    visited[y][x] = true;
    sum += (int)m[y][x] - (int)'0';

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (visited[ny][nx] || ny < 0 || nx < 0 || ny >= y_length || nx >= x_length)
        {
            continue;
        }
        
        if (m[ny][nx] == 'X') continue;
        dfs(m, ny, nx);
    }
};

vector<int> solution(vector<string> maps) {
    vector<int> answer;

    y_length = maps.size();
    x_length = maps[0].size();

    for (int i = 0; i < y_length; i++)
    {
        for (int j = 0; j < x_length; j++)
        {
            if (!visited[i][j] && maps[i][j] != 'X')
            {
                dfs(maps, i, j);
                if (sum != 0)
                {
                    answer.push_back(sum);
                    sum = 0;
                }
            }
        }
    }

    if (answer.empty())
    {
        answer.push_back(-1);
    }
    else
    {
        sort(answer.begin(), answer.end());
    }

    return answer;
}