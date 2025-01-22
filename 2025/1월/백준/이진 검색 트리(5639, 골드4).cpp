// https://www.acmicpc.net/problem/5639 : 이진 검색 트리, 5639 (c++) 

#include <iostream>

using namespace std;

int Node[10002];

void GO(int s, int e)
{
    if (s >= e) return;
    if (s == e - 1)
    {
        cout << Node[s] << '\n';
        return;
    }

    int idx = s + 1;
    for (idx; idx < e; idx++)
    {
        if (Node[s] < Node[idx])
        {
            break;
        }
    }

    GO(s + 1, idx);
    GO(idx, e);
    cout << Node[s] << '\n';

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    int idx = 0;

    while (cin >> num)
    {
        if (num == EOF) break;

        Node[idx] = num;
        idx++;
    }

    GO(0, idx);
}
