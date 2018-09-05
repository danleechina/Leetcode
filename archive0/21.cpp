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

        // auto ll1 = l1;
        // while (ll1) {
        //   cout << ll1->val << "->";
        //   ll1 = ll1->next;
        // }
        // cout << endl;
        // auto ll2 = l2;
        // while (ll2) {
        //   cout << ll2->val << "->";
        //   ll2 = ll2->next;
        // }
        // cout << endl;
        // auto cc2 = current2;
        // while (cc2) {
        //   cout << cc2->val << "->";
        //   cc2 = cc2->next;
        // }
        // cout << endl;
        // auto cc1 = current1;
        // while (cc1) {
        //   cout << cc1->val << "->";
        //   cc1 = cc1->next;
        // }
        // cout << endl << endl << endl;
      }
      return head;      
    }
};

int main(int argc, char const *argv[])
{
  auto l1 = new ListNode(-10);
  auto tmp = new ListNode(-5);
  l1->next = tmp;
  tmp->next = new ListNode(-1);

  auto l2 = new ListNode(-8);
  // tmp = new ListNode(3);
  // l2->next = tmp;
  // tmp->next = new ListNode(4);
  auto sln = Solution();
  auto result = sln.mergeTwoLists(l2, l1);
  while (result) {
    cout << result->val << "->";
    result = result->next;
  }
  cout << endl;
  return 0;
}
