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

void check(TreeNode* r)
{
  /* the code for checking is hidden. */
}

main()
{
  TreeNode* root = new TreeNode(20);
  root->left = new TreeNode(5);
  root->right = new TreeNode(40);
  root->right->left = new TreeNode(35);
  root->left->right = new TreeNode(7);
  

  check(root);
}

