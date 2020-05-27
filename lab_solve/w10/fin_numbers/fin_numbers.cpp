/*
LANG: C++
TASK: fin_numbers
*/
#include <cstdio>
#include <algorithm>
#define I (-2147483648)
using namespace std;

int a[100001];
int b[100001];
int best[100001];
int N;
int f(int u)
{
    int ttt[5] = {I,I,I,I,I};
    int maxs;
    switch (u)
    {
    case 0:
        return 0;
        break;
    case 1:
        return a[u];
        break;
    case 2:
        for (int i = 1; i <= 2; i++)
        {
            if (b[u - i])
                return a[u] + best[u-i];
            if (a[u - 3 + i] >= 0)
                return a[u] + best[u - 3 + i];
        }
        return a[u] + std::max(best[u-2],best[u-1]);
        break;
    case 3:
        for (int i = 1; i <= 3; i++)
        {
            if (b[u - i])
                return a[u] + best[u-i];
            if (a[u - 4 + i] >= 0)
                return a[u] + best[u - 4 + i];
        }
        return a[u] + std::max(std::max(best[u-3],best[u-2]),best[u-1]);
        break;
    }
    for (int i = 1; i <= 4; i++)
    {
        if (b[u - i])
            return a[u] + best[u-i];
        if (a[u - 5 + i] >= 0)
            return a[u] + best[u - 5 + i];
    }
    return a[u] + std::max(std::max(std::max(best[u-4],best[u-3]),best[u-2]),best[u-1]);
}
int main()
{
    int tmp;
    scanf("%d",&N);
    for (int i = 1; i <= N; i++)
    {
        scanf(" %d",&tmp);
        a[i] = tmp;
    }
    for (int i = 1; i <= N; i++)
    {
        scanf(" %d",&tmp);
        b[i] = tmp;
    }
    tmp = I;
    for (int u = 1; u <= N; u++)
    {
        best[u] = f(u);
        if (b[u] == 1)
            for (int qq = 1 ; qq <= 3; qq++)
            {
                best[u-qq] = best[u]; 
            }
        printf("%d\n",best[u]);
    }

    for (int u = N; u>=N-3 ;u--)
    {
        printf("--> %d\n",best[u]);
        if (b[u] == 1)
        {
            tmp = best[u];
            break;
        }
        if (tmp < best[u])
            tmp = best[u];
    }
    printf("%d\n",tmp);
}