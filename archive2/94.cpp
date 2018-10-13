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
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> result;
    if (root == nullptr) return result;
    auto sml1 = inorderTraversal(root->left);
    result.insert(result.end(), sml1.begin(), sml1.end());
    result.push_back(root->val);
    auto sml2 = inorderTraversal(root->right);
    result.insert(result.end(), sml2.begin(), sml2.end());
    return result;
  }
};