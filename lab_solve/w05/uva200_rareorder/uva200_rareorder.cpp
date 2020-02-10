/*
LANG: C++
TASK: uva200_rareorder
*/
#include <iostream>
#include <vector>
using namespace std;
int deg[27];
bool isVisited[27];
vector<int> adj[27];
void dfs(int u);
vector<int> out;
int main()
{
    ios_base::sync_with_stdio(false);
    string a,b;
    while (getline(cin,a)){
        out.clear();
        for (int u = 0; u<27; u++)
        {
            adj[u].clear();
            deg[u] = 0;
            isVisited[u] = 0;
        }
        while (true)
        {
            getline(cin,b);
            if (b.front() == '#') break;
            int lenMin = (a.length() < b.length()) ? a.length() : b.length(); 
            for (int i = 0; i < lenMin; ++i)
            {
                if (a[i] != b[i])
                {
                    deg[a[i]-'A']++;
                    adj[a[i]-'A'].push_back(b[i]-'A');
                    break;
                }
            }
            a = b;
        }
        for (int u = 0; u < 27; u++)
            if (!isVisited[u] && !adj[u].empty())
                dfs(u);
        for (int u = out.size() - 1; u>=0; u--)
            cout << (const char) (out[u]+'A');
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