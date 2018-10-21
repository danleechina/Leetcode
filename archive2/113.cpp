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
    void pathSum(TreeNode* root, int sum, vector<vector<int>>& res, vector<int>& path) {
        if (!root) return;
        path.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr && sum == root->val) {
            res.push_back(path);
        }
        if (root->left != nullptr) {
            pathSum(root->left, sum - root->val, res, path);
        }
        if (root->right != nullptr) {
            pathSum(root->right, sum - root->val, res, path);
        }
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> path;
        pathSum(root, sum, result, path);
        return result;    
    }
};