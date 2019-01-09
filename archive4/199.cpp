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
  vector<int> rightSideView(TreeNode *root)
  {
    vector<int> res;
    if (!root)
      return res;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
      int size = q.size();
      for (int i = 0; i < size; i++)
      {
        auto t = q.front();
        q.pop();
        if (t->left)
          q.push(t->left);
        if (t->right)
          q.push(t->right);
        if (i == size - 1)
          res.push_back(t->val);
      }
    }
    return res;
  }
};