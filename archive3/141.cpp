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
    bool hasCycle(ListNode *head)
    {
        ListNode *finalNode = new ListNode(0);
        ListNode *cur = head;
        while (cur)
        {
            if (cur == finalNode)
                return true;
            ListNode *n = cur->next;
            cur->next = finalNode;
            cur = n;
        }
        delete finalNode;
        return false;
    }
};