/*
LANG: C++
TASK: elephant
*/
#include <stdio.h>
#include <algorithm>
using namespace std;
int p[100001];
int a[100001];
int main()
{
    int n,tmp;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf(" %d",&tmp);
        p[i] = tmp;
    }
    int max = 0;
    for (int i=3;i<=n;i++)
    {
        a[i] = std::max(a[i-1],p[i]+a[i-3]);
        if (max < a[i]) max = a[i];
    }
    printf("%d\n",max);
}