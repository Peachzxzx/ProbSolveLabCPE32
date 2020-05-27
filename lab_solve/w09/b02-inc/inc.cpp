/*
LANG: C++
TASK: inc
*/
#include <cstdio>
using namespace std;

int a[1001];
int b[1001];

int main()
{
    int n,tmp;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf(" %d",&tmp);
        a[i] = tmp;
    }
    int max = 0;
    b[1] = 1;
    for (int i=2;i<=n;i++)
    {
        for (int j=1;j<i;j++)
        {
            if (a[i] > a[j] && b[j] > b[i])
                b[i] = b[j];   
        }
        b[i]++;
    }
    printf("%d\n",max+1);
    max = 0;
    for (int i = 1;i<=n;i++)
        if (b[i] != -1)
            if (b[i] > max)
            {
                printf("%d ",a[i]);
                max = b[i];
            }
}