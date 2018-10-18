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
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    queue<TreeNode*> st;
    st.push(root);
    while(st.size() != 0) {
      int n = st.size();
      vector<int> level;
      for (int i = 0; i < n; i ++) {
        auto t = st.front();
        st.pop();
        level.push_back(t->val);
        if (t->left) st.push(t->left);
        if (t->right) st.push(t->right);
      }
      res.insert(res.begin(), level);
    }
    return res;   
  }
};