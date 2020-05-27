/*
LANG: C++
TASK: mid58_alien
*/
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int N, a, b, R;
    scanf("%d %d %d %d", &N, &a, &b, &R);
    R = pow(R,2);
    int x, y, z;
    int count = 0;
    while (N--)
    {
        scanf(" %d %d",&x,&y);
        z = pow(a-x,2) + pow(b-y,2);
        if (R >= z) count++;
    }
    printf("%d",count);
}