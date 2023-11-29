#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> vP, vF, vS, vV, vC;
int mp, mf, ms, mv;
int n, num;
int ret = 987654321;

int cmp(int num1, int num2)
{
    string src;
    int cnt1 = 0;
    string dest;
    int cnt2 = 0;
    for (int t = 0; t < n; t++)
    {
        if (num1 & (1 << t))
        {
            src += to_string(t + 1);
            src += " ";
            cnt1++;
        }
    }

    for (int t = 0; t < n; t++)
    {
        if (num2 & (1 << t))
        {
            dest += to_string(t + 1);
            dest += " ";
            cnt2++;
        }
    }

    int idx = 0;
    while (true)
    {
        
        if (src[idx] > dest[idx])
        {
            return num2;
        }
        else if (src[idx] < dest[idx])
        {
            return num1;
        }
        
        idx++;
    }

}

void calc()
{
    for (int i = 0; i < (1 << n); i++)
    {
        int p = 0; int f = 0; int s = 0; int v = 0; int c = 0;

        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                p += vP[j];
                f += vF[j];
                s += vS[j];
                v += vV[j];
                c += vC[j];
            }
        }

        if (p >= mp && f >= mf && s >= ms && v >= mv)
        {
            if (ret > c)
            {
                ret = min(ret, c);
                num = i;
            }
            else if (ret == c)
            {
                num = cmp(num, i);
            }
        }
    }
}

int main()
{
    cin >> n;
    cin >> mp >> mf >> ms >> mv;

    for (int i = 0; i < n; i++)
    {
        int tp, tf, ts, tv, tc;

        cin >> tp >> tf >> ts >> tv >> tc;

        vP.push_back(tp);
        vF.push_back(tf);
        vS.push_back(ts);
        vV.push_back(tv);
        vC.push_back(tc);
    }
    calc();

    if (ret == 987654321)
    {
        cout << -1;
    }
    else
    {
        cout << ret << endl;

        for (int i = 0; i < n; i++)
        {
            if (num & (1 << i))
            {
                cout << i + 1 << " ";
            }
        }
    }
}