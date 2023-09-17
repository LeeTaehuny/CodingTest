/** https://www.acmicpc.net/problem/7568 [구현, 브루트포스 알고리즘] */

#include <iostream>

using namespace std;

int num;
int cnt = 1;
pair<int, int> arr[50];

int main() 
{
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (arr[i].first < arr[j].first && arr[i].second < arr[j].second)
            {
                cnt++;
            }
        }

        cout << cnt << ' ';
        cnt = 1;
    }
}