#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
bool myfunction (int i,int j) { return (i<j); }

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;
    if (!p && q) return false;
    if (p && !q) return false;
    if (p->val != q->val) return false;
    if (!isSameTree(p->left, q->left)) return false;
    return isSameTree(p->right, q->right);
  }
};