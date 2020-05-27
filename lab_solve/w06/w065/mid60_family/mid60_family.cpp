/*
LANG: C++
TASK: mid60_family
*/
#include <cstdio>
using namespace std;

int ani[1001];

bool find(int from, int to)
{
    if (from == to)
        return true;
    if (from == 0)
        return false;
    return find(ani[from],to);    
}

int main()
{
    int N,M, count = 2, tmp, tmp2;
    scanf("%d %d",&N,&M);
    N--;
    while (N--)
    {
        scanf(" %d",&tmp);
        ani[count++] = tmp;
    }
    while (M--)
    {
        scanf(" %d %d", &tmp, &tmp2);
        if (find(tmp,tmp2))
            printf("%d\n",tmp2);
        else if (find(tmp2,tmp))
            printf("%d\n",tmp);
        else
            printf("-1\n");
    }
}