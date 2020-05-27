/*
LANG: C++
TASK: milk
*/
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 100001;
const int MAX_M = 200001;

int parent[MAX_N];
int rnk[MAX_N];
int n;
int m;

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
bool q(int u, int v) {return find(u) == find(v);}
void c(int u, int v) {if (!q(u,v)) set_union(u,v);}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    char a;
    int w,e;
    init_union_find();
    for (int i = 0; i<m; i++)
    {
        cin >> a >> w >> e;
        switch (a)
        {
        case 'q':
            if (q(w,e)) cout << "yes" << "\n";
            else cout << "no" << "\n";
            break;
        case 'c':
            c(w,e);
        }
    }
}