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
  void connect(TreeLinkNode *root, TreeLinkNode *preNextRight) {
    if (!root) return;
    root->next = preNextRight;
    connect(root->left, root->right);
    if (preNextRight) {
      connect(root->right, preNextRight->left);
    } else {
      connect(root->right, nullptr);
    }
  }

  void connect(TreeLinkNode *root) {
    connect(root, nullptr);
  }
};