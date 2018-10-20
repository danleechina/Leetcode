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
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;
        int length = 0;
        ListNode *tmp = head;
        while(tmp) {
            tmp = tmp->next;
            length ++;
        }
        int middle = length/2;
        ListNode *preMiddle = nullptr;
        tmp = head;
        while (middle > 0) {
            preMiddle = tmp;
            tmp = tmp->next;
            middle --;
        }
        cout << length << " " << tmp->val;
        if (preMiddle) cout << " " << preMiddle->val;
        cout << endl;
        if (preMiddle) preMiddle->next = nullptr;
        TreeNode *root = new TreeNode(tmp->val);
        if (preMiddle) root->left = sortedListToBST(head);
        root->right = sortedListToBST(tmp->next);
        return root;
    }
};