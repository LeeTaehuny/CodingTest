#include <iostream>
#include <string>

using namespace std;
int N;
int cnt;
int i;
string temp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	while (true)
	{
		temp = to_string(i);
		if (temp.find("666") != string::npos)
		{
			cnt++;
		}

		if (cnt == N)
		{
			cout << i;
			break;
		}
		else
		{
			i++;
		}
	}
}