#include <iostream>
#include <stack>
using namespace std;

int n;
string str;
bool visited[200002];

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> str;

	stack<pair<char, int>> sv;
	stack<pair<char, int>> comp;

	// save Stack 데이터 삽입
	for (int i = 0; i < str.size(); i++)
	{
		sv.push(make_pair(str[i], i));
	}

	// save Stack 에서 compare 스택으로 값 이동
	while (!sv.empty())
	{
		// save Stack에 저장된 맨 위 요소 가져오기
		pair<char, int> temp = sv.top();
		sv.pop();

		// compare Stack이 비어있는 경우
		if (comp.empty())
		{
			// 그대로 삽입
			comp.push(temp);
		}
		// compare Stack이 비어있지 않은 경우
		else
		{
			// 맨 위 요소와 비교 (문자만)
			// * 같은 경우
			if (temp.first == comp.top().first)
			{
				// 그대로 삽입
				comp.push(temp);
			}
			// * 다른데 반대 방향 인 경우
			else if (comp.top().first == '(' && temp.first == ')')
			{
				// 그대로 삽입
				comp.push(temp);
			}
			// * 다르고 괄호가 완성되는 경우 
			else if (comp.top().first == ')' && temp.first == '(')
			{
				// visited 배열에서 해당 두 칸의 인덱스 true
				visited[comp.top().second] = true;
				visited[temp.second] = true;

				// comp 배열에서 top 삭제
				comp.pop();
			}
		}
	}

	int mx = -1;
	int idx = 0;
	for (bool b : visited)
	{
		if (b)
		{
			idx++;
		}
		else
		{
			if (mx < idx)
			{
				mx = idx;
			}

			idx = 0;
		}
	}

	if (mx == -1)
		cout << 0;
	else
		cout << mx;
}
