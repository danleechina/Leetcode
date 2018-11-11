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
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        bool hasLoop = false;
        while (fast && fast->next && fast->next->next)
        {
            fast = fast->next->next;
            if (fast == slow)
            {
                hasLoop = true;
                break;
            }
            slow = slow->next;
        }
        if (!hasLoop)
            return nullptr;
        int loopLength = 1;
        while (fast->next)
        {
            if (fast->next == slow)
                break;
            fast = fast->next;
            loopLength++;
        }
        ListNode *ans = head;
        for (int i = 0;; i++)
        {
            ListNode *tmp = ans;
            for (int j = 0; j < loopLength; j++)
                tmp = tmp->next;
            if (tmp == ans)
                break;
            ans = ans->next;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    ListNode *a = new ListNode(3);
    ListNode *a1 = new ListNode(2);
    ListNode *a2 = new ListNode(0);
    ListNode *a3 = new ListNode(4);
    a->next = a1;
    a1->next = a2;
    a2->next = a3;
    a3->next = a1;
    auto res = s.detectCycle(a);
    return 0;
}
