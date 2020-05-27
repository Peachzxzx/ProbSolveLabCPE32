/*
LANG: C++
TASK: mid592_water
*/
#include <cstdio>
using namespace std;
int water[1001];
int main()
{
    int N;
    scanf("%d",&N);
    int i = 1, tmp, total = 0;
    while (N--)
    {
        scanf(" %d",&tmp);
        water[i] = tmp;
        tmp = water[i-1] - water[i];
        if (tmp > 10)
        {
            tmp = tmp * 10;
            if (tmp > 700)
                tmp = 700;
            total += tmp;
        }
        i++;
    }
    printf("%d\n",total);
}