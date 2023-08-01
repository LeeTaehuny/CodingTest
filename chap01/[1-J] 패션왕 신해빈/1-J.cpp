#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

vector<int> b;
map<string, int> m;
int testNum;
int N;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string temp;

    cin >> testNum;

    for (int i = 0; i < testNum; i++)
    {
        cin >> N;
        cin.ignore();

        for (int j = 0; j < N; j++)
        {
            getline(cin, temp);
            temp = temp.substr(temp.find(" ") + 1);

            auto it = m.find(temp);
            if (it != m.end())
            {
                it->second++;
            }
            else
            {
                m.insert(make_pair(temp, 1));
            }
        }
        
        int sum = 1;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            sum = sum * (it->second + 1);
        }

        cout << sum - 1 << endl;
        m.clear();
    }
}