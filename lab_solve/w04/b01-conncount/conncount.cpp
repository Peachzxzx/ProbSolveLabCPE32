/*
LANG: C++
TASK: conncount
*/
#include <stdio.h>
#include <vector>
using namespace std;
#define MAX_N 100010
vector<int> adj[MAX_N];
int deg[MAX_N];
int n,m;
void readInput()
{
    scanf("%d %d",&n,&m);
    for (int u = 0;u<n;u++)
        deg[u] = 0;
    int u,v;
    for (int i = 0; i<m;i++)
    {
        scanf(" %d %d",&u,&v);
        u--;v--;
        deg[u]++;deg[v]++;
        adj[u].push_back(v);adj[v].push_back(u);
    }
}
bool isVisited[MAX_N];

void dfs(int u)
{
    isVisited[u] = true;

    for(int i=0; i<deg[u]; i++)
    {
        int v = adj[u][i];    
        if(!isVisited[v])
            dfs(v);
    }
}

void init()
{
    for (int u = 0;u<n;u++)
        isVisited[u] = 0;
}

int main()
{
    readInput();
    init();
    int c = 0;
    for (int u=0; u<n;u++)
    {
        if (!isVisited[u])
        {
            dfs(u);
            c++;
        }
    }
    printf("%d",c);
}
