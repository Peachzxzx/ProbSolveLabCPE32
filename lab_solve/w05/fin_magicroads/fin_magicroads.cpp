/*
LANG: C++
TASK: fin_magicroads
*/
#include <cstdio>
#include <vector>

using namespace std;
#define MAX_N 100001
typedef struct road
{
    int to;
    bool magic;

    road(int to, bool magic)
        : to(to), magic(magic) {};
} road;

bool visitable[MAX_N];
vector<road> roads[MAX_N];
bool vilages[MAX_N];
bool visited[MAX_N];
int deg[MAX_N];
int magic[MAX_N];

void dfs(int nowVilage, int health);
void dfsMagic(int nowVilage, int health);
int N, visitableSize = 0;
int main()
{
    int H, M, K, A, B, C;
    scanf("%u %d %d %d", &N, &M, &K, &H);
    while (K--)
    {
        scanf(" %u",&A);
        vilages[A] = true;
    }
    while (M--)
    {
        scanf(" %u %u %u", &A, &B, &C);
        roads[A].push_back(road(B,C));
        roads[B].push_back(road(A,C));
        deg[A]++;
        deg[B]++;
    }
    if (roads[1].size() == N)
    {
        printf("%u\n",N);
        return 0;
    }
    dfs(1,H);
    for (int i = 1; i<MAX_N; i++)
    {
        if (magic[i])
            dfsMagic(i,magic[i]);
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

void dfs(int nowVilage, int health)
{
    insert(nowVilage);
    if (health)
    {
        int size = deg[nowVilage];
        visited[nowVilage] = true;
        while (size--)
        {
            if (visitableSize == N) return;
            road E = roads[nowVilage][size];
            if (vilages[nowVilage])
            {
                if (magic[nowVilage] < health)
                    magic[nowVilage] = health;
                continue;
            }
            if (!visited[E.to])
                if (!E.magic)
                    dfs(E.to,health-1);
        }
        visited[nowVilage] = false;
    }
}

void dfsMagic(int nowVilage, int health)
{
    insert(nowVilage);
    if (health)
    {
        visited[nowVilage] = true;
        int size = deg[nowVilage];
        while (size--)
        {
            if (visitableSize == N) return;
            if (!visited[roads[nowVilage][size].to])
                dfsMagic(roads[nowVilage][size].to,health-1);
        }
        visited[nowVilage] = false;
    }
}