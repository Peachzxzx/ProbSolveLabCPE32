/*
LANG: C++
TASK: mid60_buyinpair
*/
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    std::vector<long long int> item;
    int N,A,B,tmp = 0,sizes;
    scanf("%d %d %d",&N,&A,&B);
    sizes = B-1;
    while (N--)
    {
        scanf(" %d",&tmp);
        if (tmp > sizes)
            continue;
        else
            item.push_back(tmp);
    }
    long long int qwe = 0;
    std::sort(item.begin(),item.end());
    sizes = item.size();
    int res1, res2;
    for (int i = 0; i < sizes; i++)
    {
        res1 = 0;
        res2 = 0;
        if (i == sizes - 1) break;
        for (int j = sizes - 1; j > i; j--)
        {
            
            if ((item[j] + item[i]) <= B)
            {    
                res1 = j;
                break;
            }
        }
        if (res1 == 0) continue;
        for (int j = i + 1; j <= res1; j++)
        {
            if ((item[j] + item[i]) >= A)
            {
                qwe += res1 - j + 1;
                break;
            }
        }
    }
    printf("%lld\n",qwe);
}