/*
LANG: C++
TASK: uva514_rails
*/
#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
    int length;
    j:
    while (scanf(" %d",&length),length !=0)
    {
        k:
        int trainNow = 1,in,wantedTrain[length];
        stack<int> station;
        for (int i = 0; i<length;i++)
        {
            scanf(" %d",&in);
            if (in == 0) 
            {
                printf("\n");
                goto j;
            }
            wantedTrain[i] = in;  
        }
        for (int i = 0;i<length;i++)
        {
            while (trainNow <= length+1)
            {
                if (!station.empty())
                {
                    if (station.top() == wantedTrain[i])
                    {
                        station.pop();
                        break;
                    }
                }
                station.push(trainNow++);
            }
        }
        if (station.empty())
            printf("Yes\n");
        else
            printf("No\n");
        goto k;
    }
}