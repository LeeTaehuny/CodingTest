/** https://www.acmicpc.net/problem/2884 [수학, 사칙연산] */

#include <iostream>
#include <stdlib.h>

using namespace std;

int H[24];
int M[60];

int hNum, mNum;

int main()
{
	for (int i = 0; i < 24; i++)
	{
		H[i] = i;
	}

	for (int i = 0; i < 60; i++)
	{
		M[i] = i;
	}

	cin >> hNum >> mNum;

	int hIdx = hNum;
	int mIdx = mNum;

	if (mNum - 45 < 0)
	{
		hIdx--;
		mIdx = 60 - abs(mNum - 45);
	}
	else
	{
		mIdx -= 45;
	}

	if (hIdx < 0)
	{
		hIdx = 23;
	}

	cout << H[hIdx] << " " << M[mIdx];
}