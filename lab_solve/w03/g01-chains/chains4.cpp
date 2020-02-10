/*
LANG: C++
TASK: chains
*/
#include <stdio.h>
using namespace std;

typedef struct Node
{
	int val;
	struct Node *next;
	struct Node *prev;
	Node(int val=0, Node *prev=0, Node *next=0)
		: val(val), next(next), prev(prev) {}
} Node;

int main()
{
    int a, b, dnaCount=1, c, res = 0, e;
    char d;
    scanf("%d %d",&a,&b);
    int dnaLength[a], result[b];
    for (int i = 0;i<a;i++)
    {
        scanf(" %d",&c);
        dnaLength[i] = c;
        res += c;
    }
    Node *dnaChain[res], *pos; 
    for (int i = 0;i<a;i++)
    {
        Node *previous = NULL;
        for (c = 0; c<dnaLength[i]; c++)
        {
            dnaChain[dnaCount-1] = new Node(dnaCount);
            if (previous)
            {
                previous->next = dnaChain[dnaCount-1];
                dnaChain[dnaCount-1]->prev = previous;
            }
            previous = dnaChain[dnaCount-1];
            dnaCount++;
        }
    }
    pos = dnaChain[0];
    for (int i = 0;i<b;i++)
    {
        scanf(" %c",&d);
        switch (d)
        {
            case 'B':
                if (pos->prev) pos = pos->prev;
                break;
            case 'F':
                if (pos->next) pos = pos->next;
                break;
            case 'C':
                scanf(" %d",&e);
                if (pos->next) pos->next->prev = 0;
                if (dnaChain[e-1]->prev) dnaChain[e-1]->next = dnaChain[e-1]->prev;
                pos->next = dnaChain[e-1];
                dnaChain[e-1]->prev = pos;
                pos = pos->next; 
                break;
        }
        if (pos->next)
        {
            Node *res = pos->next;
            if (res->next == pos)
            {
                res->next = res->prev;
                res->prev = pos;
            }
        }
        result[i] = pos->val;
    }
    for (int i=0;i<b;i++)
        printf("%d\n",result[i]);
}