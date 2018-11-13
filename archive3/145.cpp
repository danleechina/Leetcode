#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;
bool myfunction(int i, int j) { return (i < j); }

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
  vector<int> postorderTraversal(TreeNode *root)
  {
    vector<int> res;
    if (!root)
      return res;
    stack<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
      auto t = q.top();
      // q.pop();
      bool inserted = false;
      if (t->right)
      {
        inserted = true;
        q.push(t->right);
        t->right = nullptr;
      }
      if (t->left)
      {
        inserted = true;
        q.push(t->left);
        t->left = nullptr;
      }
      if (!inserted)
      {
        q.pop();
        res.push_back(t->val);
      }
    }
    return res;
  }
};