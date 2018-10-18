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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd) {
    if (preorder.size() == 0) return nullptr;
    if (inStart >= inEnd) return nullptr;
    TreeNode *root = new TreeNode(preorder[0]);
    int findRootInInorderIndex = -1;
    for (int i = inStart; i < inEnd; i ++) {
      if (inorder[i] == preorder[0]) {
        findRootInInorderIndex = i;
        break;
      }
    }
    if (findRootInInorderIndex != -1) {
      if (findRootInInorderIndex == inStart) {
        vector<int> newPreOrder(preorder.begin() + 1, preorder.end());
        root->right = buildTree(newPreOrder, inorder, findRootInInorderIndex, inEnd);
      } else if (findRootInInorderIndex == inEnd) {
        vector<int> newPreOrder(preorder.begin() + 1, preorder.end());
        root->left = buildTree(newPreOrder, inorder, inStart, findRootInInorderIndex);
      } else {
        vector<int> newLPreOrder, newRPreOrder;
        vector<int> leftElement(inorder.begin() + inStart, inorder.begin() + findRootInInorderIndex);
        sort(leftElement.begin(), leftElement.end(), myfunction);
        for (int i = 1; i < preorder.size(); i ++) {
          bool hasFindInLeft = binary_search(leftElement.begin(), leftElement.end(), preorder[i]);
          if (hasFindInLeft) {
            newLPreOrder.push_back(preorder[i]);
          } else {
            newRPreOrder.push_back(preorder[i]);
          }
        }
        root->left = buildTree(newLPreOrder, inorder, inStart, findRootInInorderIndex);
        root->right = buildTree(newRPreOrder, inorder, findRootInInorderIndex, inEnd);
      }
    }
    return root;
  }

  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return buildTree(preorder, inorder, 0, inorder.size());
  }
};

int main(int argc, char const *argv[])
{
  Solution s;
  vector<int> pr = {3,9,20,15,7};
  vector<int> in = {9,3,15,20,7};
  s.buildTree(pr, in);
  return 0;
}
