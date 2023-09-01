#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int n;


int main()
{
	cin >> n;

	int team;
	int min, sec;
	int scoreA = 0, scoreB = 0;
	int timeA = 0, timeB = 0;

	int cur = 0;

	for (int i = 0; i < n; i++) {

		cin >> team;
		scanf("%2d:%2d", &min, &sec);

		if (scoreA > scoreB) {
			timeA += min * 60 + sec - cur;
		}
		else if (scoreA < scoreB) {
			timeB += min * 60 + sec - cur;
		}

		if (team == 1) {
			scoreA++;
		}
		else {
			scoreB++;
		}

		cur = min * 60 + sec;
	}

	if (scoreA > scoreB) {
		timeA += 2880 - cur;
	}
	else if (scoreA < scoreB) {
		timeB += 2880 - cur;
	}


	printf("%02d:%02d\n", timeA / 60, timeA % 60);
	printf("%02d:%02d\n", timeB / 60, timeB % 60);

	return 0;
}