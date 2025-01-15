// https://www.acmicpc.net/problem/1043 : 거짓말, 1043 (c++) 

#include <iostream>
#include <vector>

using namespace std;

// n : 사람의 수
// m : 파티의 수
int n, m;

// 진실을 아는 사람들의 배열
vector<int> v;

// 파티별 참여 인원 현황
vector<int> partys[52];
// 인원별 파티 참여 현황
vector<int> persons[52];

// 방문처리 배열
bool visited[52];
// 파티 참여 제외 여부
bool T[52];

void DFS(int curr)
{
    // 해당 노드 방문 처리
    visited[curr] = true;

    // 해당 노드가 참여한 파티를 순회
    for (int party : persons[curr])
    {
        // 참여 불가 처리
        T[party] = true;

        // 해당 파티에 참여한 노드 순회
        for (int person : partys[party])
        {
            // 만약 아직 방문하지 않은 노드인 경우
            if (visited[person] == false)
            {
                // 재귀 호출
                DFS(person);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    // 진실을 아는 사람들을 입력받기
    int temp;
    cin >> temp;

    for (int i = 0; i < temp; i++)
    {
        int tempNum;
        cin >> tempNum;

        // 진실을 아는 사람들 저장
        v.push_back(tempNum);
    }

    // 파티를 순회하며 연결 관계 계산
    for (int i = 0; i < m; i++)
    {
        // 파티 참여 인원 입력받기
        int tempNum;
        cin >> tempNum;

        for (int j = 0; j < tempNum; j++)
        {
            int joinNum;
            cin >> joinNum;

            // 파티에 해당 인원 참여 표시
            partys[i].push_back(joinNum);
            // 인원에 해당 파티 참여 표시
            persons[joinNum].push_back(i);
        }
    }

    // 진실을 알고 있는 인원을 순회합니다.
    for (int i = 0; i < v.size(); i++)
    {
        // 만약 아직 방문되지 않은 사람인 경우
        if (visited[v[i]] == false)
        {
            // DFS 순회
            DFS(v[i]);
        }
    }

    int cnt = 0;

    // 전체 목록을 순회하며 참여 가능한 파티의 수 누적
    for (int i = 0; i < m; i++)
    {
        if (T[i] == false)
        {
            cnt++;
        }
    }

    cout << cnt;
}
