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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;

        auto nextKHead = head;
        int length = 0;
        while (nextKHead && length != k) {
            length ++;
            nextKHead = nextKHead->next;
        }
        if (length == k) {
            auto currentHead = head;
            auto newTail = head;
            auto current = newTail->next;
            while (current->next != nextKHead) {
                auto tmp = current->next;
                current->next = currentHead;
                currentHead = current;
                newTail->next = tmp;
                current = tmp;
            }
            auto tmp = current->next;
            current->next = currentHead;
            currentHead = current;
            newTail->next = reverseKGroup(nextKHead, k);
            return currentHead;
        } else {
            return head;
        }
    }
};

int main() {

  auto l1 = new ListNode(1);
  auto tmp = new ListNode(2);
  l1->next = tmp;
  auto t = new ListNode(3);
  tmp->next = t;
  tmp = t;
  t = new ListNode(4);
  tmp->new = t;
  tmp = t;
  t = new ListNode(5);
  tmp->new = t;

    auto sln = Solution();
    auto result = sln.reverseKGroup(s, 3);
    for(auto element: result) {
        cout << element->val << "->"
    }
    cout << endl;
}