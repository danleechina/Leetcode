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
  bool isValidBST(TreeNode* root, int64_t minValue, int64_t maxValue) {
    if (!root) return true;
    int64_t c = root->val;
    if (c > minValue && c < maxValue) {
      return isValidBST(root->left, minValue, c) && isValidBST(root->right, c, maxValue);
    }
    return false;
  }

  bool isValidBST(TreeNode* root) {
    if (!root) return true;
    bool res = true;
    res = res && isValidBST(root->left, ((int64_t)INT_MIN) - 1, root->val);
    cout << res << endl;
    res = res && isValidBST(root->right, root->val, ((int64_t)INT_MAX) + 1);
    cout << res << endl;
    return res;
  }
};
