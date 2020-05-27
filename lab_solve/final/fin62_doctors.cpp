#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX_N 100010
#define MAX_M 200010
typedef struct edge {
	int dest, weight;
	edge(int d, int w)
		: dest(d), weight(w) {}
} edge;
int aa[MAX_N];
vector<edge> adjList[100010];
int N,M,L;
bool discovered[MAX_N];
void BFS(int source, int dest, int N,int cost)
{
	discovered[source] = true;
	vector<int> predecessor(N, -1);
	queue<int> q,co;
	q.push(source);
	co.push(0);
	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		int cc = co.front();
		co.pop();
		if (curr == dest)
		{
			re;
		}
		for (edge u : adjList[curr])
		{
			int v = u.dest;
			if (!discovered[v])
			{
				discovered[v] = true;
				if (aa[dest] > cost + aa[curr])
				aa[dest] = cost + aa[curr];
				BFS(curr,v,N,cc);
				q.push(v);
				co.push(cc + u.weight);
				predecessor[v] = curr;
			}
		}
	}
}
int main()
{
	for (int i = 0; i<= MAX_N ; i++)
	{
		aa[i] = MAX_M;
	}
	int a,b,c;
	cin >> N >> M >> L;
	for (int i = 0 ; i < N ; i++)
	{
		cin >> a;
	}
	aa[1] = 0;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		adjList[a].push_back(edge(b,c));
		adjList[b].push_back(edge(a,c));
	}

	int source = 1, dest = 3;
	BFS(source, dest, N, 0);

	return 0;
}