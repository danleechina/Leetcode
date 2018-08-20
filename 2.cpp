#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode *ret = nullptr;
      ListNode *current = nullptr;
      int carryBit = 0;
      while(l1 || l2) {
        auto value1 = 0;
        if (l1) {
          value1 = l1->val;
        }
        auto value2 = 0;
        if (l2) {
          value2 = l2->val;
        }
        auto sum = value1 + value2 + carryBit;
        auto lastBit = sum - sum/10 * 10;
        carryBit = sum/10;
        if (current == nullptr) {
          ret = new ListNode(lastBit);
          current = ret;
        } else {
          current->next = new ListNode(lastBit);
          current = current->next;
        }
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
      }
      if (carryBit > 0) {
        current->next = new ListNode(carryBit);
      }
      return ret;
    }
};

int main() {
  auto sln = Solution();
  auto list1 = ListNode(1);
  auto list2 = ListNode(7);

  // list1.next = ListNode(8);
  // list2.next = ListNode(8);
  auto ret = sln.addTwoNumbers(&list1, &list2);
  while(ret) {
    std::cout << ret->val;
    std::cout << "\n";
    ret = ret->next;
  }
  return 0;
}