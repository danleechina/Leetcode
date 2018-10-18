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
bool myfunction (int i,int j) { return (i<j); }

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (postorder.size() == 0) return nullptr;
    TreeNode *root = new TreeNode(postorder.back());
    int inIndex = 0;
    for(; inIndex < inorder.size(); inIndex ++) {
      if (inorder[inIndex] == postorder.back()) break;
    }
    if (inIndex > 0) {
      vector<int> newInOrder(inorder.begin(), inorder.begin() + inIndex);
      vector<int> newPostOrder(postorder.begin(), postorder.begin() + inIndex);
      root->left = buildTree(newInOrder, newPostOrder);
    }
    if (inIndex < inorder.size() - 1) {
      vector<int> newInOrder(inorder.begin() + inIndex + 1, inorder.end());
      vector<int> newPostOrder(postorder.begin() + inIndex, postorder.end() - 1);
      root->right = buildTree(newInOrder, newPostOrder);
    }
    return root;
  }
};