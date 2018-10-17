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

  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    vector<TreeNode*> stackOne, stackTwo;
    stackOne.push_back(root);
    while(!stackOne.empty() || !stackTwo.empty()) {
      vector<int> levelRes;
      if (stackOne.empty()) {
        while(!stackTwo.empty()) {
          auto top = stackTwo.front();
          stackTwo.erase(stackTwo.begin(), stackTwo.begin() + 1);
          if (top->left) stackOne.push_back(top->left);
          if (top->right) stackOne.push_back(top->right);
          levelRes.push_back(top->val);
        }
      } else {
        while(!stackOne.empty()) {
          auto top = stackOne.front();
          stackOne.erase(stackOne.begin(), stackOne.begin() + 1);
          if (top->left) stackTwo.push_back(top->left);
          if (top->right) stackTwo.push_back(top->right);
          levelRes.push_back(top->val);
        }
      }
      // cout << endl;
      // cout << "stack One: ";
      // for (auto a: stackOne) {
      //   cout << a->val << " ";
      // }
      // cout << endl;
      // cout << "stack Two: ";
      // for (auto a: stackTwo) {
      //   cout << a->val << " ";
      // }
      res.push_back(levelRes);
    }
    return res;
  }
};