/*
LANG: C++
TASK: bstdelete
*/
#include <cstdio>

typedef struct node
{
    int val;
    node *left;
    node *right;
    bool del;
    node(int val, node *left = NULL, node *right = NULL, bool del = false)
        : val(val), left(left), right(right), del(del) {}
} node;

void insert(node *&r, int x)
{
    if(!r)
        r = new node(x);
    else if (r->val == x)
        r->del = false;
    else if (x < r->val)
        insert(r->left,x);
    else if(x > r->val)
        insert(r->right,x);
}

int find(node* r, int x)
{
    if (r == 0)
        return 0;
    else if (r->val == x)
        if (r->del)
            return 0;
        else
            return 1;
    else if (x < r->val)
        return find(r->left,x);
    else if (x > r->val)
        return find(r->right,x);
    else
        return 0;
}

void deleteNgo(node* r, int x)
{
    if (r == 0)
        return;
    else if (r->val == x)
        r->del = true;
    else if (x < r->val)
        deleteNgo(r->left,x);
    else if (x > r->val)
        deleteNgo(r->right,x);
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
            printf("%d\n",find(r,e));
            break;
        case 3:
            deleteNgo(r,e);
            break;    
        }
    } 
}