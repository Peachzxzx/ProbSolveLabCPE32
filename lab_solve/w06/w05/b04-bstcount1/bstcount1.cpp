/*
LANG: C++
TASK: bstcount1
*/
#include <cstdio>

using namespace std;
typedef struct node
{
    int val;
    node *left;
    node *right;
    node(int val, node *left = NULL, node *right = NULL)
        : val(val), left(left), right(right) {}
} node;

void insert(node *&r, int x)
{
    if(!r)
        r = new node(x);
    else if (x < r->val)
        insert(r->left,x);
    else if(x > r->val)
        insert(r->right,x);
}
int count(node *r, int x)
{
    if (r)
    {
        if (r->val > x)
            return (count(r->left,x) + 1 + count(r->right,x));
        else
            return count(r->right,x);
    }
    return 0;
}

int main()
{
    int q,w,e;
    node *r = 0;
    scanf("%d",&q);
    while (q--)
    {
        scanf(" %d %d", &w, &e);
        switch (w)
        {
        case 1:
            insert(r,e);
            break;
        case 2:
            printf("%d\n",count(r,e));
            break;
        }
    }
    return 0;
}