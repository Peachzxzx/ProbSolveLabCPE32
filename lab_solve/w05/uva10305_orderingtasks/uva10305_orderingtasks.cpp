/*
LANG: C++
TASK: uva10305_orderingtasks
*/
#include <iostream>
#include <vector>
using namespace std;
int deg[101];
bool isVisited[101];
vector<int> adj[101];
void dfs(int u);
vector<int> out;
int main()
{
    ios_base::sync_with_stdio(false);
    int n,m,i,j;
    while (cin >> n >> m, n != 0 || m != 0){
        out.clear();
        for (int u = 0; u<101; u++)
        {
            adj[u].clear();
            deg[u] = 0;
            isVisited[u] = 0;
        }
        while (m--)
        {
            cin >> i >>j;
            deg[i]++;
            adj[i].push_back(j);
        }
        for (int u = 1; u<=n;u++)
            if (!isVisited[u]) dfs(u);
        for (int u = n-1; u>=0; u--)
        {
            cout << out[u];
            if(u) cout << ' ';
        }
        cout << "\n";
    }
    return 0;
}

void dfs(int u)
{
    isVisited[u] = true;
    for(int i=0; i<deg[u]; i++)
    {
        int v = adj[u][i];    
        if(!isVisited[v])
            dfs(v);
    }
    out.push_back(u);
}