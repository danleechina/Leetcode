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

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int deep(TreeNode *root) {
        if (!root) return 0;
        int leftDeep = deep(root->left);
        int rightDeep = deep(root->right);
        return  max(leftDeep, rightDeep) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        int leftDeep = deep(root->left);
        int rightDeep = deep(root->right);
        if (abs(leftDeep - rightDeep) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};