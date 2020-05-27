/*
LANG: C++
TASK: mid62_ttt
*/
#include <vector>
#include <cstdio> 
using namespace std; 

vector<int> adj[1001]; 
vector<bool> visited(1001); 
vector<int> color(1001);

bool isBipartite(int v)
{
    int qweqwq = adj[v].size();
    while (qweqwq--)
    {
        int u = adj[v][qweqwq];
        if (!visited[u])
        {
            visited[u] = true;
            color[u] = !color[v];
            if (!isBipartite(u)) 
                return false; 
        }
        else if (color[u] == color[v])
        {
            printf("%d %d",u,v);
            return false; 
        } 
            
    } 
    return true; 
}
int N,M;
int main()
{
    scanf("%d %d",&N,&M);
    int a,b;
    
    while (M--)
    {
        scanf(" %d %d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    visited[1] = true; 
    color[1] = 0;
    isBipartite(1); 
} 