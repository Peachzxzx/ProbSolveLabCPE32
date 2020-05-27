/*
LANG: C++
TASK: uva10600_acmcontest
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_N = 100010;
const int MAX_M = 300000;

int parent[MAX_N];
int rnk[MAX_N];
int n;
int m;
int edges[MAX_M][2];
int weights[MAX_M];
pair<int,int> wpairs[MAX_M];

void init_union_find()
{
  for(int i=0; i<n; i++) {
    parent[i] = i;
    rnk[i] = 0;
  }
}

int find(int u)  // no path compression
{
  while(parent[u] != u) {
    u = parent[u];
  }
  return u;
}

void set_union(int u, int v)  // union by rank
{
  u = find(u);
  v = find(v);  
  if(u != v) {
    if(rnk[u] < rnk[v]) {
      parent[u] = v;
    } else if(rnk[v] < rnk[u]) {
      parent[v] = u;
    } else {
      parent[u] = v;
      rnk[v]++;
    }
  }
}

void read_input()
{
  cin >> n >> m;
  for(int i=0; i<m; i++) {
    int u,v,w;
    cin >> u >> v >> w;
    u--; v--;
    edges[i][0] = u;
    edges[i][1] = v;
    weights[i] = w;
  }
}

vector<int> mst_edges;

int find_mst(bool save_mst)
{
	for (int i=0; i<m; i++)
	{
		wpairs[i].first = weights[i];
		wpairs[i].second = i;
	}
	sort(wpairs,wpairs+m);
	init_union_find();
	int wtotal = 0;
	for (int i=0; i<m; i++)
	{
		int u, v, w, e;
		e = wpairs[i].second;
		u = edges[e][0];
		v = edges[e][1];
		w = weights[e];
		int pu, pv;
		pu = find(u);
		pv = find(v);
		if (pu != pv)
		{
			wtotal += w;
			set_union(u,v);
			if (save_mst)
				mst_edges.push_back(e);
		}
	}
	return wtotal;
}

int main() {
  int t;
  cin >> t;
  for (int tt = 0; tt<t; tt++)
  {
	  read_input();
	  mst_edges.clear();
	  int c1 = find_mst(true);
	  int c2 = 100000000;

	  for (int i = 0; i<n-1; i++)
	  {
		  int e = mst_edges[i];
		  int old_weight = weights[e];
		  weights[e] = 100000000;
		  int cc = find_mst(false);
		  if (cc < c2)
		  	c2 = cc;
		  weights[e] = old_weight;
	  }
	  cout << c1 << " " << c2 << "\n";
  }
}

