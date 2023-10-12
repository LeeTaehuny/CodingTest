#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n, k;
int dx[3] = { -1, 1, 2};
int visited[100001];
vector<int> parent(100001, -1);
vector<int> list;
int cnt = 0;

void bfs(int pos)
{
    visited[pos] = 1;
    queue<int> q;
    q.push(pos);
    
    while(!q.empty())
    {
        pos = q.front();
        q.pop();
        
        int np = 0;        

        for(int i = 0; i < 3; i++)
        {
            if (i == 2) np = pos * dx[i];
            else np = pos + dx[i];           

            if (np < 0 || np >= 100001) continue;
            if (visited[np]) continue;        
            visited[np] = visited[pos] + 1;
            
            if (np == k)
            {
                cnt = visited[np] - 1;
                parent[np] = pos;
                break;
            }

            q.push(np);
            parent[np] = pos;
        }
    }
}

int main()

{
    cin >> n >> k;

    bfs(n);
    
    cout << cnt << endl;
    
    bool run = true;
    
    int temp = parent[k];
    list.push_back(k);
    while(run)
    {
        if (temp == -1) break;
        
        list.push_back(temp);
        temp = parent[temp];
    }
    
    for (auto it = list.end() - 1; it != list.begin() - 1; it--)
    {
        cout << *it << " ";
    }

    return 0;
}