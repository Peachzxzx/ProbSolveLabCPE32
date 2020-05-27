/*
LANG: C++
TASK: mid59_mask
*/
#include <cstdio>
using namespace std;

typedef struct asd
{
    int value;
    int number;
} asd;

int main()
{
    asd qwe[5];
    int N;
    scanf("%d",&N);
    int tmp, count = 0;
    for (int i = 1; i < 5; ++i)
    {
        qwe[i].value = 0;
        for (int j = 0; j<N; ++j)
        {
            count++;
            scanf(" %d",&tmp);
            if (tmp > (qwe[i]).value)
            {
                (qwe[i]).value = tmp;
                (qwe[i]).number = count;
            }
        }
    }
    if (qwe[1].value > qwe[2].value)
    {
        if (qwe[3].value > qwe[4].value)
        {
            if (qwe[1].value > qwe[3].value)
            {
                printf("%d %d %d %d\n",qwe[1].number,qwe[3].number,qwe[2].number,qwe[4].number);
            }
            else
            {
                printf("%d %d %d %d\n",qwe[3].number,qwe[1].number,qwe[2].number,qwe[4].number);
            }
        }
        else
        {
            if (qwe[1].value > qwe[4].value)
            {
                printf("%d %d %d %d\n",qwe[1].number,qwe[4].number,qwe[2].number,qwe[3].number);
            }
            else
            {
                printf("%d %d %d %d\n",qwe[4].number,qwe[1].number,qwe[2].number,qwe[3].number);
            }
        }
    }
    else
    {
        if (qwe[3].value > qwe[4].value)
        {
            if (qwe[2].value > qwe[3].value)
            {
                printf("%d %d %d %d\n",qwe[2].number,qwe[3].number,qwe[1].number,qwe[4].number);
            }
            else
            {
                printf("%d %d %d %d\n",qwe[3].number,qwe[2].number,qwe[1].number,qwe[4].number);
            }
        }
        else
        {
            if (qwe[2].value > qwe[4].value)
            {
                printf("%d %d %d %d\n",qwe[2].number,qwe[4].number,qwe[1].number,qwe[3].number);
            }
            else
            {
                printf("%d %d %d %d\n",qwe[4].number,qwe[2].number,qwe[1].number,qwe[3].number);
            }
        }
    }
}