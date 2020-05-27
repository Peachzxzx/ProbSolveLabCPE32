/*
LANG: C++
TASK: mid61_prfriends
*/
#include <cstdio>
using namespace std;

bool prime[200001];

void isPrime(int n)
{
    for (int i = 2; i<n ;i++)
    {
        prime[i] = true;
    }
    for (int p=2; p*p<=n; p++) 
    {
        
        if (prime[p] == true) 
        {
            for (int i=p*p; i<=n; i += p)
                prime[i] = false; 
        }
    } 
}

int main()
{
    int L,R;
    scanf("%d %d",&L,&R);
    int count = 0;
    while (L<R)
        if (prime[L++]) count++;
    printf("%d\n",(count+1)/2);
}