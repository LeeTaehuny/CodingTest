#include <iostream>
using namespace std;

int a, b, c, Start, End;
int arr1[101];
int sum[101];


int main()
{
	cin >> c >> b >> a;

	for (int i = 0; i < 3; i++)
	{
		cin >> Start >> End;

		for (int i = 1; i < sizeof(arr1) / sizeof(int); i++)
		{
			arr1[i] = i;

		}

		for (int i = Start + 1; i <= End; i++)
		{
			sum[i]++;
		}
	}

	int result = 0;

	for (int i = 0; i < size(sum); i++)
	{
		switch (sum[i])
		{
		case 1:
			result += (c * 1);
			break;
		case 2:
			result += (b * 2);
			break;
		case 3:
			result += (a * 3);
			break;
		}
	}

	cout << result << endl;
}

/*
#include <bits/stdc++.h>
using namespace std;
int A, B, C, a, b, cnt[104], ret;
int main(){
	cin >> A >> B >> C;
	for(int i = 0; i < 3; i++){
		cin >> a >> b;
		for(int j = a; j < b; j++)cnt[j]++;
	}
	for(int j = 1; j < 100; j++){
		if(cnt[j]){
			if(cnt[j] == 1) ret += A;
			else if(cnt[j] == 2)ret += B * 2;
			else if(cnt[j] == 3)ret += C * 3;
		}
	}
	cout << ret << "\n";
	return 0;
}
*/