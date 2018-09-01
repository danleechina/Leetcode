#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      if (l2 == nullptr) return l1;
      if (l1 == nullptr) return l2;
      ListNode *head;
      ListNode *current1;
      ListNode *current2;
      ListNode *preCurrent1 = nullptr;
      if (l1->val <= l2->val) {
        current1 = l1;
        current2 = l2;
        head = l1;
      } else {
        current1 = l2;
        current2 = l1;
        head = l2;
      }
      while(current1 || current2) {
        if (current1 == nullptr) {
          preCurrent1->next = current2;
          break;
        }
        if (current2 == nullptr) {
          break;
        }
        while (current1 && current1->val <= current2->val) {
          preCurrent1 = current1;
          current1 = current1->next;
        }
        if (current1 == nullptr) {
          preCurrent1->next = current2;
          break;
        }
        
        auto tmp = current1;
        preCurrent1->next = current2;
        current1 = current2->next;
        preCurrent1 = current2;
        current2 = tmp;
      }
      return head;      
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
      if (lists.size() == 0) return nullptr;
      auto result = lists[0];
      int i = 1;
      while (i < lists.size()) {
        result = mergeTwoLists(result, lists[i]);
        i ++;
      }
      return result;
    }
};