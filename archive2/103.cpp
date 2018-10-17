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
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    queue<TreeNode*> current;
    if (!root) return res;
    current.push(root);
    bool isLeftToRight = true;
    while(!current.empty()) {
      vector<int> levelResult;
      int cnt = current.size();
      for (int i = 0; i < cnt; i ++ ){
        auto top = current.front();
        current.pop();
        if (top->left) current.push(top->left);
        if (top->right) current.push(top->right);
        levelResult.push_back(top->val);
      }
      if (!isLeftToRight) reverse(levelResult.begin(), levelResult.end());
      isLeftToRight = !isLeftToRight;
      res.push_back(levelResult);
    }
    return res;
  }
};