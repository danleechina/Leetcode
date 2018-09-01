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
    ListNode* swapPairs(ListNode* head) {
      if (head == nullptr) return nullptr;
      if (head->next == nullptr) return head;
      auto result = head->next;
      auto s1 = head;
      auto s2 = s1->next;
      
      auto s3 = s2->next;
      s2->next = s1;
      s1->next = swapPairs(s3);
      return result;
    }
};