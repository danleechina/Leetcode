/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
  ListNode *removeElements(ListNode *head, int val)
  {
    ListNode *n = new ListNode(-1);
    n->next = head;
    auto cur = n->next, prev = n;
    while (cur)
    {
      if (cur->val == val)
      {
        auto t = cur->next;
        prev->next = t;
        delete cur;
        cur = t;
      }
      else
      {
        prev = cur;
        cur = cur->next;
      }
    }
    return n->next;
  }
};