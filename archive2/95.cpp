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
    TreeNode* copyATree(TreeNode* root) {
        if (!root) return nullptr;
        TreeNode *newRoot = new TreeNode(root->val);
        newRoot->left = copyATree(root->left);
        newRoot->right = copyATree(root->right);
        return newRoot;
    }

    void generateTrees(int minValue, int maxValue, vector<TreeNode*> &result) {
        for (int i = minValue; i <= maxValue; i ++) {
            vector<TreeNode*> leftResult;
            generateTrees(minValue, i - 1, leftResult);
            vector<TreeNode*> rightResult;
            generateTrees(i + 1, maxValue, rightResult);
            // cout << leftResult.size() << " " << rightResult.size() << endl;
            if (leftResult.size() == 0) {
                if (rightResult.size() == 0) {
                    TreeNode *root = new TreeNode(i);
                    result.push_back(root);
                }
                for (auto r: rightResult) {
                    TreeNode *root = new TreeNode(i);
                    root->right = r;
                    result.push_back(root);
                }
            } else if (rightResult.size() == 0) {
                if (leftResult.size() == 0) {
                    TreeNode *root = new TreeNode(i);
                    result.push_back(root);
                }
                for (auto l: leftResult) {
                    TreeNode *root = new TreeNode(i);
                    root->left = l;
                    result.push_back(root);
                }
            } else {
                for (int i = 0; i < leftResult.size(); i ++) {
                    for (int j = 0; j < rightResult.size(); j ++) {
                        TreeNode *root = new TreeNode(i);
                        root->left = i == leftResult.size() - 1 ? leftResult[i] : copyATree(leftResult[i]);
                        root->right = j == rightResult.size() - 1 ? rightResult[j] : copyATree(rightResult[j]);
                        result.push_back(root);
                    }
                }
            }
        }
    }

    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> result;
        generateTrees(1, n, result);
        return result;
    }
};

void printTree(TreeNode *root) {
    if (!root) {
        cout << "null" << " ";
        return;
    }
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

int main(int argc, char const *argv[])
{
    Solution s;
    auto res = s.generateTrees(2);
    for (auto r: res) {
        printTree(r);
        cout << endl;
    }
    return 0;
}
