/*
LANG: C++
TASK: bipartite
*/

#include <cstdio>
#include <vector>
using namespace std;

vector<int> adj[100001];
bool visited[100001];
int color[100001];
int N;
bool dfs(int node)
{
    for (int i = 0; i < adj[node].size(); i++)
    {
        int v = adj[node][i];
        if (!visited[v])
        {
            visited[v] = true;
            color[v] = !color[node];
            if (!dfs(v)) return false;
        }
        else if (color[v] == color[node]) return false;
    }
    return true;
}

int main()
{
    int K,M,u,v;
    scanf("%d",&K);
    while(K--)
    {
        scanf(" %d %d",&N,&M);
        for (int i = 0 ; i<100001; i++)
        {
            adj[i].clear();
            visited[i] = false;
            color[i] = false;
        }
        while(M--)
        {
            scanf(" %d %d",&u,&v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        color[1] = 1;
        visited[1] = true;
        if (dfs(1))
            printf("Yes\n");
        else
            printf("No\n");
    }
}