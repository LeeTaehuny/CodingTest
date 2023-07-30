#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 난쟁이라고 주장하는 사람들의 총 숫자
int n = 9;
// 실제 난쟁이 숫자
int k = 7;

// 주장하는 사람들의 키를 저장할 배열 (사이즈 : 9)
vector<int> a(n);
// 값을 비교하기 위한 배열
vector<int> v;

// 최초 1번만 추출하면 되므로 추출되었는지 판별하기 위한 변수
bool run = true;

// 입력을 받는 함수를 정의합니다.
void Input()
{
    for (int i = 0; i < 9; i++)
    {
        cin >> a[i];
    }
}

// 조합을 계산할 함수를 정의합니다.
void Combi(int start, vector<int>& v)
{
    // 이미 출력된 값이 있는 경우도 체크합니다.
    if (k == (int)v.size() && run)
    {
        int sum = 0;

        for (int i : v)
        {
            sum += i;
        }

        if (sum == 100)
        {
            sort(v.begin(), v.end());
            for (int i : v)
            {
                cout << i << endl;
            }
            run == false;
        }
        return;
    }

    for (int i = start + 1; i < n; i++)
    {
        v.push_back(a[i]);
        Combi(i, v);
        v.pop_back();
    }
}

int main()
{
    Input();
    Combi(-1, v);
}