/*
LANG: C++
TASK: uva12602_nicelicenseplates
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int g;
    while(scanf("%d",&g) != EOF)
    {
        char q,w,e;
        int a;
        while (g--)
        {
            scanf(" %c%c%c-%d",&q,&w,&e,&a);
            q = q - 'A';
            w = w - 'A';
            e = e - 'A';
            int z=q*676+w*26+e;
            int c = abs(z-a);
            if (c <= 100)
                printf("nice\n");
            else
                printf("not nice\n");
        }
    }
    return 0;
}