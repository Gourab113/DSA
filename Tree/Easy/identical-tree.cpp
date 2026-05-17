
// 100. Same Tree
// Two tree same if there structure and value same

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  bool identical(TreeNode *p, TreeNode *q)
  {

    if (p == nullptr || q == nullptr)
    {
      return p == q;
    }

    if (p->val != q->val)
      return false;

    return identical(p->left, q->left) && identical(p->right, q->right);
  }
  bool isSameTree(TreeNode *p, TreeNode *q)
  {
    if (p == nullptr && q == nullptr)
    {
      return true;
    }
    if (p == nullptr || q == nullptr)
      return false;

    return identical(p, q);
  }
};