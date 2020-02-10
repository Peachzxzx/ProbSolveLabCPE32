#include <iostream>

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
  /* the code is hidden. */

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

main()
{
  TreeNode* root = 0;

  int n,k;
  cin >> n >> k;
  for(int i=0; i<n; i++) {
    int x;
    cin >> x;
    insert(root,x);
  }
  for(int i=0; i<k; i++) {
    int x;
    cin >> x;
    if(find(root,x)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}

