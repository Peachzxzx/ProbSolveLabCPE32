/*
LANG: C++
TASK: uva100_3n1
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int work(int a,int b)
{
    if (a>b) std::swap(a,b);
    int max = 0;
    for (int i = b;i>=a;i--)
    {
        unsigned long j = i;
        int k = 1;
        while (j > 1)
        {
            k++;
            j = (j % 2 == 0) ? (j / 2) : (3 * j + 1);
        }
        max = (max < k) ? k : max;
    }
    return max;
}

int main()
{
    int x,y;
    do {
        int r = scanf("%d %d",&x,&y);
        if (r!=2) break;
        printf("%d %d %d\n",x,y,work(x,y));
    } while(true);
}