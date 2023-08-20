#include <iostream>
#include <stdio.h>
using namespace std;

int M;

int adj[68][68];


void zip(int minY, int minX, int size)
{
	bool allZero = true;
	bool allOne = true;



	for (int i = minY; i < minY + size; i++)
	{
		for (int j = minX; j < minX + size; j++)
		{
			if (adj[i][j] == 1)
			{
				allZero = false;
			}

			if (adj[i][j] == 0)
			{
				allOne = false;
			}
		}
	}

	// all 0, all 1이 아니라면?
	if (!allZero && !allOne)
	{
		cout << "(";

		// 1사분면
		zip(minY, minX, size / 2);
		// 2사분면
		zip(minY, minX + (size / 2), size / 2);
		// 3사분면
		zip(minY + (size / 2), minX, size / 2);
		// 4사분면
		zip(minY + (size / 2), minX + (size / 2), size / 2);

		cout << ")";
	}

	// all 0라면?
	if (allZero)
	{
		cout << "0";
	}

	// all 1이라면?
	if (allOne)
	{
		cout << "1";
	}

}

int main()
{
	scanf_s("%d", &M);

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf_s("%1d", &adj[i][j]);
		}
	}
	int n = 0;
	zip(0, 0, M);
}