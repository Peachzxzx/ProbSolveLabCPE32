/*
LANG: C++
TASK: bstfind2
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

void selectionSort(int a[], int n) {
   int i, j, min, temp;
   for (i = 0; i < n - 1; i++) {
      min = i;
      for (j = i + 1; j < n; j++)
         if (a[j] < a[min])
            min = j;
      temp = a[i];
      a[i] = a[min];
      a[min] = temp;
   }
}

int find(node* r, int x)
{
    if (r == 0)
        return 0;
    else if (r->val == x)
        return 1;
    else if (x < r->val)
        return find(r->left,x);
    else if (x > r->val)
        return find(r->right,x);
    else
        return 0;
}

node *arrayToBst(int a[], int start, int end)
{
    if (start > end) return 0;
    int mid = (start+end) / 2;
    node *r = new node(a[mid]);
    r->left = arrayToBst(a,start,mid-1);
    r->right = arrayToBst(a,mid+1,end);
    return r;
}

int FU[200000] = {};
int main()
{
    int q,w,e,t = 0,y = t;
    node *r = 0;
    scanf("%d", &q);
    while(q--)
    {
        scanf(" %d %d", &w, &e);
        switch (w)
        {
        case 1:
            FU[t] = e;
            t++;
            break;
        case 2:
            if (t != y)
            {
                selectionSort(FU,t);
                r = arrayToBst(FU,0,t-1);
                y = t;
            }
            printf("%d\n",find(r,e));
            break;
        }
    }
    return 0;
}