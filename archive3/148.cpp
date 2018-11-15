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
  ListNode *mergeList(ListNode *list1, ListNode *list2)
  {
    if (!list1)
      return list2;
    if (!list2)
      return list1;
    ListNode *res = list1;
    ListNode *cur1Pre = nullptr;
    ListNode *cur1 = list1;
    ListNode *cur2 = list2;
    while (cur2)
    {
      while (cur1 && cur2->val > cur1->val)
      {
        cur1Pre = cur1;
        cur1 = cur1->next;
      }
      if (cur1)
      {
        if (cur1Pre)
        {
          cur1Pre->next = cur2;
          ListNode *tmp = cur2->next;
          cur2->next = cur1;
          cur1Pre = cur2;
          cur2 = tmp;
        }
        else
        {
          ListNode *tmp = cur2->next;
          cur2->next = cur1;
          cur1Pre = cur2;
          res = cur2;
          cur2 = tmp;
        }
      }
      else
      {
        cur1Pre->next = cur2;
        break;
      }
    }
    return res;
  }
  ListNode *sortList(ListNode *head)
  {
    if (!head)
      return nullptr;
    if (head->next == nullptr)
      return head;
    ListNode *preSlow = nullptr;
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast)
    {
      preSlow = slow;
      slow = slow->next;
      fast = fast->next;
      if (fast)
      {
        fast = fast->next;
      }
    }
    preSlow->next = nullptr;
    ListNode *l1 = sortList(head);
    ListNode *l2 = sortList(slow);
    ListNode *res = mergeList(l1, l2);
    printNode(l1);
    printNode(l2);
    printNode(res);
    return res;
  }
};