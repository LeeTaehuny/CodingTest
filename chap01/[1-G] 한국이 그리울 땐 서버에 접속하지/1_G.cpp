#include <iostream>
#include <string>
using namespace std;

int N;

int main()
{
	string P;
	string word[100];

	cin >> N;
	cin >> P;

	for (int i = 0; i < N; i++)
	{
		cin >> word[i];
	}

	int idx = P.find("*");

	string pre = P.substr(0, idx);
	string post = P.substr(idx + 1);

	for (int i = 0; i < N; i++)
	{
		if (word[i].size() < pre.size() + post.size())
		{
			cout << "NE" << endl;
		}
		else
		{
			string pre2 = word[i].substr(0, idx);
			string post2 = word[i].substr(word[i].size() - post.size());

			if (pre2.compare(pre) == 0 && post2.compare(post) == 0)
			{
				cout << "DA" << endl;
			}
			else
			{
				cout << "NE" << endl;
			}
		}
	}
}