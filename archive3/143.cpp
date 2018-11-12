#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;
bool myfunction(int i, int j) { return (i < j); }

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
  void printNode(ListNode *head)
  {
    while (head)
    {
      cout << head->val << ' ';
      head = head->next;
    }
    cout << endl;
  }
  void reorderList(ListNode *head)
  {
    if (!head)
      return;
    ListNode *preHalfHead = nullptr;
    ListNode *halfHead = head;
    ListNode *cur = head;
    while (cur)
    {
      cur = cur->next;
      if (cur)
      {
        cur = cur->next;
      }
      preHalfHead = halfHead;
      halfHead = halfHead->next;
    }
    preHalfHead->next = nullptr;
    printNode(head);
    printNode(halfHead);
    ListNode *tmp = nullptr;
    if (!halfHead)
    {
      return;
    }
    cur = halfHead->next;
    halfHead->next = nullptr;
    while (cur)
    {
      tmp = cur->next;
      cur->next = halfHead;
      halfHead = cur;
      cur = tmp;
    }
    printNode(head);
    printNode(halfHead);
    ListNode *cur1 = head;
    ListNode *cur2 = halfHead;
    while (cur1 && cur2)
    {
      tmp = cur1->next;
      cur = cur2->next;
      cur1->next = cur2;
      cur2->next = tmp;
      cur1 = tmp;
      cur2 = cur;
    }
    printNode(head);
  }
};

int main(int argc, char const *argv[])
{
  Solution s;
  ListNode *a0 = new ListNode(1);
  ListNode *a1 = new ListNode(2);
  ListNode *a2 = new ListNode(3);
  ListNode *a3 = new ListNode(4);
  ListNode *a4 = new ListNode(5);
  ListNode *a5 = new ListNode(6);
  ListNode *a6 = new ListNode(7);
  a0->next = a1;
  a1->next = a2;
  a2->next = a3;
  a3->next = a4;
  a4->next = a5;
  a5->next = a6;
  s.reorderList(a0);
  return 0;
}
