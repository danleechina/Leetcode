#include <iostream>
#include <vector>
#include <map>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode * current = head;
      int i = 0;
      while (i < n) {
        current = current->next;
        i ++;
      }
      ListNode * prevN1 = nullptr;
      ListNode * prevN = head;
      while (current) {
        current = current->next;
        prevN1 = prevN;
        prevN = prevN->next;
      }
      if (prevN1 == nullptr) {
        return head->next;
      } else {
        prevN1->next = prevN->next;
        return head;
      }

    }
};