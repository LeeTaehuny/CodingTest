// https://www.acmicpc.net/problem/1647 : 도시 분할 계획, 1647 (c++) 

#include <iostream>
#include <queue>

using namespace std;

int n, m;

int parent[100002];
int mx;
int mx_dist;

struct Node
{
	Node() { }
	Node(int InStart, int InEnd, int InDist)
		: start(InStart), end(InEnd), dist(InDist) { }

	int start = 0;
	int end = 0;
	int dist = 0;
};

struct Comp
{
	bool operator()(const Node& n1, const Node& n2)
	{
		return n1.dist > n2.dist;
	}
};

int Find(int a)
{
	if (parent[a] != a)
	{
		parent[a] = Find(parent[a]);
	}

	return parent[a];
}

bool Check(int a, int b)
{
	a = Find(a);
	b = Find(b);

	return a != b;
}

void Visited(int a, int b)
{
	a = Find(a);
	b = Find(b);

	parent[b] = a;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	priority_queue<Node, vector<Node>, Comp> pq;

	for (int i = 0; i < m; i++)
	{
		int s, e, d;
		cin >> s >> e >> d;

		pq.push(Node(s, e, d));
		pq.push(Node(e, s, d));
	}

	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}

	while (!pq.empty())
	{
		Node node = pq.top();
		pq.pop();

		if (Check(node.start, node.end))
		{
			// 노드 통합
			Visited(node.start, node.end);

			// 길이 통합
			mx += node.dist;
			// 노드 간의 간선의 가장 큰 길이 저장
			mx_dist = max(mx_dist, node.dist);
		}
	}

	// 최종 길이 - 가장 큰 길이 = 분리된 마을의 길 길이
	cout << mx - mx_dist;
}
