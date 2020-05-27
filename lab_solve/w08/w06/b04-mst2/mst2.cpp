/*
LANG: C++
TASK: mst2
*/
#include <iostream>
#include <algorithm>
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

    wpairs[i].first = w;
    wpairs[i].second = i;
  }
}

int main() {
  read_input();
  sort(wpairs, wpairs+m);
  init_union_find();
  int count = 0;
  for(int i=0; i<m; i++) {
    int u, v, w, e;
    e = wpairs[i].second;
    u = edges[e][0];
    v = edges[e][1];
    w = weights[e];
    if (find(u) != find(v))
    {
      set_union(u,v);
      count += w;
    }
  }
  cout << count << "\n";
}

