/*
LANG: C++
TASK: bstprint
*/
#include <cstdio>

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
  if(!r) {
    r = new node(x);
  } else if(x < r->val) {
    insert(r->left,x);
  } else if(x > r->val) {
    insert(r->right,x);
  }
}
void printFromRight(node *r, int t)
{
    if (r->right)
        printFromRight(r->right,t+1);
    for (int i = 0;i<t;i++)
        printf("...");
    printf("* %d\n",r->val);
    if (r->left)
        printFromRight(r->left,t+1);
}

int main()
{
   int q,w;
   scanf("%d",&q);
   q--;
   scanf(" %d",&w);
   node *e = new node(w);
   while (q--)
   {
       scanf("%d",&w);
       insert(e,w);
   }
   printFromRight(e,0);
}