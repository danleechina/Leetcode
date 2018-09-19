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
  void printList(ListNode *node) {
    while(node) {
      cout << node->val << " ";
      node = node->next;
    }
  }

  ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr) return head;
    ListNode *end = head;
    int length = 1;
    while (end->next != nullptr) {
      length ++;
      end = end->next;
    }

    int headCount = length - k % length;
    k = k % length;
    if (k == 0) return head;

    ListNode *newEnd = head;
    for (int i = 1; i < headCount; i ++) {
      newEnd = newEnd->next;
    }
    ListNode *kthNode = newEnd->next;
    newEnd->next = nullptr;
    end->next = head;
    return kthNode;
  }
};