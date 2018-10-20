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

    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int leftDeep = minDepth(root->left);
        int rightDeep = minDepth(root->right);
        if (leftDeep == 0) leftDeep = rightDeep;
        if (rightDeep == 0) rightDeep = leftDeep;
        return  min(leftDeep, rightDeep) + 1;
    }
};