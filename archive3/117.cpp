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


struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
  void connect(TreeLinkNode *root) {
    if (!root) return;
    queue<TreeLinkNode*> q;
    q.push(root);
    while(!q.empty()) {
      int cnt = q.size();
      TreeLinkNode *first = q.front();
      q.pop();
      if (first->left) q.push(first->left);
      if (first->right) q.push(first->right);
      for (int i = 1; i < cnt; i ++) {
        first->next = q.front();
        first = q.front();
        q.pop();
        if (first->left) q.push(first->left);
        if (first->right) q.push(first->right);
      }
    }
  }
};