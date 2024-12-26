// https://www.acmicpc.net/problem/1991 : 트리 순회, 1991 (c++) 

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int n;
map<char, int> alpha;
vector<int> adj[28];

void PrintPreOrder(int cnt)
{
    if (cnt < 0) return;

    // 노드 출력
    char alphabat = cnt + 'A';
    cout << alphabat;

    // 왼쪽으로 이동
    PrintPreOrder(adj[cnt][0]);

    // 오른쪽으로 이동
    PrintPreOrder(adj[cnt][1]);
}

void PrintInOrder(int cnt)
{
    if (cnt < 0) return;

    // 왼쪽으로 이동
    PrintInOrder(adj[cnt][0]);

    // 노드 출력
    char alphabat = cnt + 'A';
    cout << alphabat;

    // 오른쪽으로 이동
    PrintInOrder(adj[cnt][1]);
}

void PrintPostOrder(int cnt)
{
    if (cnt < 0) return;

    // 왼쪽으로 이동
    PrintPostOrder(adj[cnt][0]);

    // 오른쪽으로 이동
    PrintPostOrder(adj[cnt][1]);

    // 노드 출력
    char alphabat = cnt + 'A';
    cout << alphabat;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 연결된 노드 입력받기
    cin >> n;

    alpha.insert(make_pair('.', -1));

    for (int i = 0; i < 26; i++)
    {
        char alphabat = 'A' + i;
        alpha.insert(make_pair(alphabat, i));
    }

    for (int i = 0; i < n; i++)
    {
        char node, left, right;

        cin >> node >> left >> right;

        adj[alpha[node]].push_back(alpha[left]);
        adj[alpha[node]].push_back(alpha[right]);
    }

    PrintPreOrder(0);
    cout << '\n';
    PrintInOrder(0);
    cout << '\n';
    PrintPostOrder(0);
}