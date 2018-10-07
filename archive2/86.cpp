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
    ListNode* partition(ListNode* head, int x) {
        ListNode *smaller = new ListNode(-1);
        ListNode *bigger = new ListNode(-1);
        ListNode *smallerEnd = smaller;
        ListNode *biggerEnd = bigger;
        for (ListNode *tmp = head; tmp != NULL;) {
            if (tmp->val < x) {
                smallerEnd->next = tmp;
                smallerEnd = tmp;
            } else {
                biggerEnd->next = tmp;
                biggerEnd = tmp;
            }
            ListNode *node = tmp->next;
            biggerEnd->next = nullptr;
            smallerEnd->next = nullptr;
            tmp = node;
        }
        ListNode *result;
        if (smaller->next) {
            result = smaller->next;
            smallerEnd->next = bigger->next;
        } else {
            result = bigger->next;
        }
        delete smaller;
        delete bigger;
        return result;
    }
};