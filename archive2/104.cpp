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
  int maxDepth(TreeNode* root) {   
    if (!root) return 0;
    queue<TreeNode*> current;
    current.push(root);
    int deep = 0;
    while(!current.empty()) {
      int cnt = current.size();
      for (int i = 0; i < cnt; i ++ ){
        auto top = current.front();
        current.pop();
        if (top->left) current.push(top->left);
        if (top->right) current.push(top->right);
      }
      deep ++;
    }
    return deep;
  }
};