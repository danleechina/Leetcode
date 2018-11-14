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
  ListNode *insertionSortList(ListNode *head)
  {
    ListNode *res = head;
    ListNode *preI = nullptr;
    for (ListNode *i = head; i;)
    {
      ListNode *preJ = nullptr;
      bool changed = false;
      for (ListNode *j = res; j != i; j = j->next)
      {
        if (j->val > i->val)
        {
          if (preJ)
          {
            preJ->next = i;
            preI->next = i->next;
            i->next = j;
          }
          else
          {
            preI->next = i->next;
            i->next = j;
            res = i;
          }
          changed = true;
          break;
        }
        preJ = j;
      }
      if (changed)
      {
        i = preI->next;
      }
      else
      {
        preI = i;
        i = i->next;
      }
    }
    return res;
  }
};