// https://www.acmicpc.net/problem/1197 : 최소 스패닝 트리, 1197 (c++) 

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int v, e;
int visited[10002];

struct Node
{
	Node() { }
	Node(int InStart, int InEnd, int InDist) : start(InStart), end(InEnd), dist(InDist) {}

	int start = 0;
	int end = 0;
	int dist = 0;
};

struct Comp
{
	bool operator()(const Node& p1, const Node& p2)
	{
		return p1.dist > p2.dist;
	}
};

int find(int x)
{
	if (visited[x] != x) 
	{
		visited[x] = find(visited[x]);
	}
	
	return visited[x];
}

void Visited(int a, int b)
{
	a = find(a);
	b = find(b);

	visited[b] = a;
}

bool check(int a, int b)
{
	a = find(a);
	b = find(b);

	// 다르면 추가할 수 있다는 의미
	return a != b;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> v >> e;

	// 우선순위 큐 생성 (연결 간선의 길이가 짧은 순으로 정렬)
	priority_queue<Node, vector<Node>, Comp> pq;

	for (int i = 0; i < e; i++)
	{
		int a, b, length;

		cin >> a >> b >> length;

		pq.push(Node(a, b, length));
		pq.push(Node(b, a, length));
	}

	// 방문 노드 초기화
	for (int i = 0; i <= v; i++)
	{
		visited[i] = i;
	}

	int mx = 0;

	while (!pq.empty())
	{
		// 첫 데이터 추출
		Node node = pq.top();
		pq.pop();

		// node의 end의 최상단 부모 노드와 start의 최상단 부모 노드가 같은지 확인하기
		// * 달라야 체크 가능
		if (check(node.start, node.end))
		{
			// 두 노드 병합
			// * 도착 지점의 최상단 부모를 시작 지점의 최상단으로 설정
			Visited(node.end, node.start);

			// 길이 누적
			mx += node.dist;
		}
	}

	cout << mx;
}
