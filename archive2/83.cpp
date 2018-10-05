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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        auto lastNode = head;
        auto current = head->next;
        int lastVal = head->val;
        while (current) {
            if (current->val == lastVal) {
                auto tmp = current->next;
                lastNode->next = tmp;
                current = tmp;
            } else {
                lastVal = current->val;
                lastNode = current;
                current = current->next;
            }
        }
        return head;
    }
};