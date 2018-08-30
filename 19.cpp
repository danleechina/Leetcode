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
      vector<ListNode*> dup;
      auto tmp = head;
      while(tmp) {
        dup.push_back(tmp);
        tmp = tmp->next;
      }
      int lengthOfNode = dup.size();
      auto toBeDeleted = dup[lengthOfNode - n];
      if (toBeDeleted == dup[0]) {
        return toBeDeleted->next;
      } else {
        auto preToBeDeleted = dup[lengthOfNode - n - 1];
        preToBeDeleted->next = toBeDeleted->next;
        return head;
      }
    }
};