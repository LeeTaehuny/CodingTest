#include <iostream>

using namespace std;

int N;
int K;

int pSum[100001];
int MaxNum = -987654321;

int main()
{
    cin >> N >> K;

    for (int i = 1; i < N; i++)
    {
        int num;
        cin >> num;

        pSum[i] = pSum[i - 1] + num;
    }

    for (int i = K; i <= N; i++)
    {
        MaxNum = std::max(MaxNum, pSum[i] - pSum[i - K]);
    }

    cout << MaxNum << endl;
}