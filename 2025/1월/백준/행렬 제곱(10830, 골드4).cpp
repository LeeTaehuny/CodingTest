// https://www.acmicpc.net/problem/10830 : 행렬 제곱, 10830 (c++) 

#include <iostream>
#include <vector>

using namespace std;

int n;
// b의 경우 int를 초과한 입력값을 받기에 long long 타입으로 선언
long long b;
vector<vector<int>> res;
vector<vector<int>> adj;

// 행렬 제곱
vector<vector<int>> Calc(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    // 배열 초기화
    vector<vector<int>> temp;
    temp.resize(5);
    for (int i = 0; i < 5; i++)
    {
        temp[i].resize(5, 0);
    }

    // arr의 제곱 구현
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                temp[i][j] += (arr1[i][k] * arr2[k][j]);
                temp[i][j] %= 1000;
            }
        }
    }

    return temp;
}

// 분할정복
vector<vector<int>> Devide(long long m, vector<vector<int>> v)
{
    // 곱셈 공식은 행렬이든 일반 수든 그대로 적용됨
    // 즉, A의 N승은 다음과 같이 표현 가능함
    // * N이 짝수인 경우 : A^(n/2) * A^(n/2)
    // * N이 홀수인 경우 : A^(n/2) * A^(n/2) * A
    //  => 위 공식을 그대로 적용하면 다음과 같음.
    if (m == 1)
    {
        return v;
    }

    // 짝수 승인 경우
    if (m % 2 == 0)
    {
        vector<vector<int>> t = Devide(m / 2, v);
        return Calc(t, t);
    }
    // 홀수 승인 경우
    else
    {
        vector<vector<int>> t = Devide(m / 2, v);
        return Calc(Calc(t, t), adj);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> b;
    adj.resize(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int Tnum;
            cin >> Tnum;
            
            adj[i].push_back(Tnum);
        }
    }

    // 만약 b가 1인 경우
    if (b == 1)
    {
        // 전체를 순회하며 1000인 경우 0으로 바꿔 출력
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adj[i][j] == 1000)
                {
                    cout << 0 << " ";
                }
                else
                {
                    cout << adj[i][j] << " ";
                }
            }
            cout << '\n';
        }
    }
    else
    {
        // 제곱
        res = Devide(b, adj);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << res[i][j] << " ";
            }
            cout << '\n';
        }
    }
    
}
