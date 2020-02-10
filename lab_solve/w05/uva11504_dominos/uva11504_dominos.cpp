/*
LANG: C++
TASK: uva11504_dominos
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int deg[100010];
bool isVisited[100010];
vector<int> adj[100010];
vector<int> out;
void dfs(int u);
int main()
{
    ios_base::sync_with_stdio(false);
    int a,n,m,x=0,y=0,c=0;
    cin >> a;
    while (a--)
    {
        c=0;
        out.clear();
        for (int u = 0; u<100010; u++)
        {
            adj[u].clear();
            deg[u] = 0;
            isVisited[u] = false;
        }
        cin >> n >> m;
        while (m--)
        {
            cin >> x >> y;
            deg[x]++;
            adj[x].push_back(y);
        }
        for (int u = 0; u < n;u++)
            if (!isVisited[u])
                dfs(u);
        reverse(out.begin(),out.end());
        for (int u = 0; u<100010; u++)
            isVisited[u] = false;
        for (int i = 0; i<n; i++)
            if (!isVisited[out[i]])
            {
                dfs(out[i]);
                c++;
            }
        cout << c << "\n";
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