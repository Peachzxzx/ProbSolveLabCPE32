/*
LANG: C++
TASK: mid60_scoring
*/
#include <cstdio>
using namespace std;
#define MAX_N 101
int score[MAX_N];
int count[MAX_N];
int main()
{
    int N,M,a,b,out = 0;
    scanf("%d %d",&N,&M);
    while (M--)
    {
        scanf(" %d %d",&a,&b);
        count[a]++;
        if (b > score[a])
            score[a] = b;
    }
    while (N)
    {
        if (count[N] <= 5)
            out = out + score[N];
        N--;
    }
    printf("%d\n",out);
}