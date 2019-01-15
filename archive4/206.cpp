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
  ListNode *reverseList(ListNode *head)
  {
    if (!head)
      return head;
    ListNode *res = head, *cur = head->next;
    res->next = nullptr;
    while (cur)
    {
      ListNode *tmp = cur->next;
      cur->next = res;
      res = cur;
      cur = tmp;
    }
    return res;
  }
};