# [5 - H] 13144번: List of Unique Numbers

https://www.acmicpc.net/problem/13144

## 문제

길이가 N인 수열이 주어질 때, 수열에서 연속한 1개 이상의 수를 뽑았을 때 같은 수가 여러 번 등장하지 않는 경우의 수를 구하는 프로그램을 작성하여라.

## 입력

첫 번째 줄에는 수열의 길이 N이 주어진다. (1 ≤ N ≤ 100,000)

두 번째 줄에는 수열을 나타내는 N개의 정수가 주어진다. 수열에 나타나는 수는 모두 1 이상 100,000 이하이다.

## 입력

첫 번째 줄에는 수열의 길이 N이 주어진다. (1 ≤ N ≤ 100,000)

두 번째 줄에는 수열을 나타내는 N개의 정수가 주어진다. 수열에 나타나는 수는 모두 1 이상 100,000 이하이다.

## 출력

조건을 만족하는 경우의 수를 출력한다.

## 예제 입력 1

```
5
1 2 3 4 5

```

## 예제 출력 1

```
15

```

## 예제 입력 2

```
5
1 2 3 1 2

```

## 예제 출력 2

```
12

```

## 예제 입력 3

```
5
1 1 1 1 1

```

## 예제 출력 3

```
5
```

## 코드

```jsx
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// N : 수열의 길이
int n;

// 입력받은 수열
vector<int> v;

// 이미 방문한 수 처리용
bool visited[100001];

// 경우의 수
long long int cnt;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	// 데이터 입력받기
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		v.push_back(temp);
	}

	// 투 포인터 사용
	
	// 1. 처음부터 중복 없이 만들 수 있는 수열의 끝 찾기 
	//    -> s = 0, e = 0에서 숫자를 방문했다고 표시하면서 진행(e++)
	//    -> 만약 e번째 요소가 이미 방문한 숫자라면 그 앞까지 자르기
	//	  -> 즉, 중복이 없는 수열 꺼내기(ex, 12312라면 123)
	
	// 2. 3가지 경우의 수가 가능하다고 생각할 수 있음 (1, 12, 123)
	//    -> 해당 수만큼 경우의 수에 추가하고, s를 증가시키고, s의 방문처리 해제
	
	// 3. 다시 e를 증가시키며 중복이 없는 수열 찾기 반복
	//    -> 인덱스가 범위를 벗어나면 종료하기
	
	int s = 0;
	int e = 0;

	visited[v[s]] = true;
	while (true)
	{
		while (e < n - 1 && !visited[v[e + 1]])
		{
			// 다음 수 방문 처리
			visited[v[e + 1]] = true;
			// e 증가
			e++;
		}

		if (s >= n || e >= n) break;

		cnt += e - s + 1;
		visited[v[s]] = false;
		s++;
	}
	
	cout << cnt;
}
```