/*
LANG: C++
TASK: intsch
*/
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std; 

int find(int a[][2],int m)
{
    vector<pair<int, int>> v[2];

    for (int i = 0; i < m; i++)
        v[0].push_back(make_pair(a[i][1], a[i][0]));

    sort(v[0].begin(), v[0].end());

    int count = 1;
    int x = 0;
    for (int j = 1; j < v[0].size(); j++)
    {
        if (v[0][j].second >= v[0][x].first)
        {
                x = j;
                count++;
        }
    }
    return count;
}

int main() 
{
    int m,q,w;
    cin >> m;
    int a[m][2];
    for (int i = 0 ; i<m; i++)
    {
        cin >> q >> w;
        a[i][0] = q;
        a[i][1] = w;
    }
    cout << find(a,m);
    return 0;
}