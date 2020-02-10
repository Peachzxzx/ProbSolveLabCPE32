/*
LANG: C++
TASK: fin59_2_hos
*/
#define MAX_N 100001
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

bool visitable[MAX_N];
int N, visitableSize = 0;
vector<int> roads[MAX_N];
int level[MAX_N];
bool visited[MAX_N];
int deg[MAX_N];
queue<int> temp;
void dfsOne(int nowVilage, int health);
void dfsTwo(int nowVilage, float health);
int main()
{
    int Nk, M, K, H, A, B;
    scanf("%d %d %d %d", &Nk, &M, &K, &H);
    N = Nk;
    Nk++;
    for (int i = 0; i<K; i++)
    {
        scanf(" %d",&A);
        temp.push(A);
    }
    while (K--)
    {
        scanf(" %d",&A);
        level[temp.front()] = A+1;
        temp.pop();
    }
    while (M--)
    {
        scanf(" %d %d", &A, &B);
        roads[A].push_back(B);
        roads[B].push_back(A);
        deg[A]++;
        deg[B]++;
    }
    while (Nk--)
    {
        switch (level[Nk])
        {
        case 1:
            dfsOne(Nk, H);
            break;
        case 2:
            dfsTwo(Nk, H);
            break;
        }
    }
    printf("%d\n",visitableSize);
}

void insert(int vilage)
{
    if (!visitable[vilage])
    {
        visitable[vilage] = true;
        visitableSize++;
    }
}

void dfsOne(int nowVilage, int health)
{
    insert(nowVilage);
    if (health)
    {
        visited[nowVilage] = true;
        int size = deg[nowVilage];
        while (size--)
        {
            if (visitableSize == N) return;
            if (!visited[roads[nowVilage][size]])
                dfsOne(roads[nowVilage][size],health-1);
        }
        visited[nowVilage] = false;
    }
}

void dfsTwo(int nowVilage, float health)
{
    insert(nowVilage);
    if (health)
    {
        visited[nowVilage] = true;
        int size = deg[nowVilage];
        while (size--)
        {
            if (visitableSize == N) return;
            if (!visited[roads[nowVilage][size]])
                dfsTwo(roads[nowVilage][size],health-0.5);
        }
        visited[nowVilage] = false;
    }
}