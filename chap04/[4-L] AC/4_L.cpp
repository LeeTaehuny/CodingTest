#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

int t;
vector<int> v;
deque<int> dq;
bool front = true;

bool calc(string op)
{
	for (int i = 0; i < op.size(); i++)
	{
		if (op[i] == 'R')
		{
			front = !front;

			//reverse(v.begin(), v.end());
		}
		else if (op[i] == 'D')
		{
			if (dq.size() > 0)
			{
				if (front)
				{
					dq.pop_front();
				}
				else
				{
					dq.pop_back();
				}
				//v.erase(v.begin());
			}
			else
			{
				return false;
			}
		}
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		string op;
		cin >> op;
		int n;
		cin >> n;
		string li;
		cin >> li;

		string res = "";
		for (int k = 0; k < li.size(); k++)
		{
			if (li[k] >= '0' && li[k] <= '9')
			{
				res += li[k];
			}

			if (li[k] == ',')
			{
				//v.push_back(stoi(res));
				dq.push_back(stoi(res));
				res = "";
			}
		}
		//v.push_back(stoi(res));
		if (res.size())
			dq.push_back(stoi(res));

		if (calc(op))
		{
			cout << "[";
			
			if (front)
			{
				for (int j = 0; j < dq.size(); j++)
				{
					cout << dq[j];
					if (j + 1 < dq.size())
					{
						cout << ",";
					}
				}
			}
			else
			{
				for (int j = dq.size() - 1; j >= 0; j--)
				{
					cout << dq[j];
					if (j - 1 >= 0)
					{
						cout << ",";
					}
				}
			}
			cout << "]\n";
		}
		else
		{
			cout << "error\n";
		}

		dq.clear();
		front = true;
	}
	
}