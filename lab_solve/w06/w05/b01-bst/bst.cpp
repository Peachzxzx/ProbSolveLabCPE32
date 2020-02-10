/*
LANG: C++
TASK: bst
*/
#include <cstdio>

using namespace std;

typedef int valueType;

struct TreeNode
{
  valueType val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(valueType val, TreeNode* left=0, TreeNode* right=0)
    : val(val), left(left), right(right) {}
};

void insert(TreeNode*& r, valueType x)
{
  if(!r) {
    r = new TreeNode(x);
  } else if(x < r->val) {
    insert(r->left,x);
  } else if(x > r->val) {
    insert(r->right,x);
  }
}

TreeNode* find(TreeNode* r, valueType x)
{
  if (r == 0)
    return 0;
  else if (r->val == x)
    return r;
  else if (x < r->val)
    return find(r->left,x);
  else if (x > r->val)
    return find(r->right,x);
}

int main()
{
    int M;
    scanf("%d",&M);
    TreeNode* A = 0;
    int K,X;
    while (M--)
    {
        scanf(" %d %d",&K,&X);
        switch (K)
        {
            case 1:
                insert(A,X);
                break;
            case 2:
                if (find(A,X))
                    printf("1\n");
                else 
                    printf("0\n");
                break;
        }
    }
}