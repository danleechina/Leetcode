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

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *llNode = nullptr;
        ListNode *lNode = head;
        ListNode *currentNode = nullptr;
        ListNode *result = nullptr;
        while(lNode) {
            currentNode = lNode->next;
            if (!currentNode) {
                if (!result) result = lNode;
                break;
            }
            if (currentNode->val == lNode->val) {
                ListNode *tmp = currentNode;
                while(tmp && tmp->val == lNode->val) {
                    lNode->next = tmp->next;
                    delete tmp;
                    tmp = lNode->next;
                }
                if (llNode) {
                    llNode->next = lNode->next;
                    delete lNode;
                    lNode = llNode->next;
                } else {
                    auto tmp = lNode;
                    lNode = lNode->next;
                    delete tmp;
                }
            } else {
                if (!result) result = lNode;
                llNode = lNode;
                lNode = currentNode;
            }
        }
        return result;
    }
};