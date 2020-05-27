/*
LANG: C++
TASK: mid62_smallest
*/
#include <cstdio>
using namespace std;
#define MAX_N 200001
int H[MAX_N];
int lowFront[MAX_N];
int nearLow[MAX_N];
typedef struct Node
{
    int val;
    Node *next;

    Node(int val,Node *next = 0)
        : val(val), next(next) {}
} Node;

Node *top = 0;
void push(int val) {top = new Node(val,top);}
void pop() {if (top) top = top->next;}
bool empty() {return top == 0;}

void prevSmaller(int n)
{
    for (int i = 1; i<=n; i++)
    {
        while (top && H[top->val] >= H[i])
            top = top->next;
        if (top == 0)
            nearLow[i] = 0;
        else
            nearLow[i] = top->val;
        top = new Node(i,top);
    }
}

int main()
{
    int N,Q,tmp,l = 0,i=1,j,k;
    scanf("%d %d %d",&N,&Q,&tmp);
    int sss= N;
    N--;
    l = tmp;
    H[i] = tmp;
    lowFront[i++] = l;
    while(N--)
    {
        scanf(" %d",&tmp);
        if (tmp < l )
            l = tmp;
        H[i] = tmp;
        lowFront[i++] = l;
    }
    prevSmaller(sss);
    while(Q--)
    {
        scanf(" %d %d",&j,&k);
        switch (j)
        {
        case 1:
            printf("%d\n",(lowFront[k]));
            break;
        case 2:
            int i = sss;
            if (lowFront[i] > k)
            {
                printf("%d\n",sss);
                break;
            }
            while (i > 0)
            {
                if (H[i] < k)
                    i--;
                else if (H[i] >= k)
                {
                    if (lowFront[i] >= k)
                        break;
                    else i = nearLow[i];
                }
            }
            printf("%d\n",i);
            break;
        }
    }
}