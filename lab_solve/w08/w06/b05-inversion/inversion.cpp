/*
LANG: C++
TASK: inversion
*/
#include <stdio.h>

int list[100001];
int tmp[100001];
long long int out;
long long int inversion(int start, int end)
{
    long long int count = 0;
    long long int count2 = 0;
    if (start < end)
    {
        int mid = (start + end) / 2;
        count += inversion(start,mid);
        count += inversion(mid+1,end);
        int leftSidePtr = start;
        int rightSidePtr = mid+1;
        int tmpPtr = start;
        while ((leftSidePtr <= mid-1) && (rightSidePtr <= end))
        {
            if (list[leftSidePtr] <= list[rightSidePtr])
            {
                tmp[tmpPtr++] = list[leftSidePtr++];
                
            }
            else
            {
                tmp[tmpPtr++] = list[rightSidePtr++];
                count += (mid - leftSidePtr);
            }
        }
        while (leftSidePtr <= mid-1)
        {
            tmp[tmpPtr++] = list[leftSidePtr++];
        }
        while (rightSidePtr <= end)
        {
            tmp[tmpPtr++] = list[rightSidePtr++];
        }
        for (int i = start; i<=end; i++)
        {
            list[i] = tmp[i];
        }
    }
    return count;
}
int main()
{
    int a,q;
    scanf("%d",&a);
    for (int i = 0; i<a; i++)
    {
        scanf(" %d",&q);
        list[i] = q;
    }
    out = inversion(0,a-1);
    printf("%lld",out);
}