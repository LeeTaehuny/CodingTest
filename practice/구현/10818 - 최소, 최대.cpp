/** https://www.acmicpc.net/problem/10818 [구현, 수학]*/

#include <iostream>
using namespace std;

int N;
int Arr[1000000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> Arr[i];
    }

    int min = 1000004;
    int max = -1000004;

    for (int i = 0; i < N; i++)
    {
        if (min > Arr[i])
        {
            min = Arr[i];
        }

        if (max < Arr[i])
        {
            max = Arr[i];
        }
    }
    cout << min << " " << max;
}