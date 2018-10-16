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
  bool isSameValue(TreeNode* left, TreeNode* right) {
    if (!left && !right) return true;
    if (!left && right) return false;
    if (left && !right) return false;
    if (left->val != right->val) return false;
    return isSameValue(left->right, right->left) && isSameValue(left->left, right->right);
  }

  bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    return isSameValue(root->left, root->right);
  }
};