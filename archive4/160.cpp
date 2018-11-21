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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
  {
    ListNode *cur1 = headA, *cur2 = headB;
    while (cur1 != cur2)
    {
      cur1 = cur1 ? cur1->next : headB;
      cur2 = cur2 ? cur2->next : headA;
    }
    return cur1;
  }
};