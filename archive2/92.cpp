#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
bool myfunction (int i,int j) { return (i<j); }

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

  void printNode(ListNode *node) {
    while(node) {
      cout << node->val << " ";
      node = node->next;
    }
    cout << endl;
  }

  ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (m == n) return head;
    int currentIndex = 1;
    ListNode* result = new ListNode(-1);
    ListNode* currentNode = head;
    ListNode* preCurrentNode = result;
    ListNode* mHeadNode = result;
    result->next = currentNode;
    while (currentNode) {
      // cout << mHeadNode->val << endl;
      // cout << currentNode->val << endl;
      if (currentIndex > m && currentIndex <= n) {
        auto tmp = mHeadNode->next;
        mHeadNode->next = currentNode;
        auto temp = currentNode->next;
        currentNode->next = tmp;
        preCurrentNode->next = temp;
        currentNode = temp;
      } else if (currentIndex == m) {
        preCurrentNode = currentNode;
        currentNode = currentNode->next;
      } else if (currentIndex < m) {
        mHeadNode = mHeadNode->next;
        preCurrentNode = currentNode;
        currentNode = currentNode->next;
      } else {
        break;
      }
      currentIndex ++;
      // printNode(result);
    }
    auto r = result->next;
    delete result;
    return r;
  }
};

int main(int argc, char const *argv[])
{
  ListNode *n1 = new ListNode(1);
  ListNode *n2 = new ListNode(2);
  ListNode *n3 = new ListNode(3);
  ListNode *n4 = new ListNode(4);
  ListNode *n5 = new ListNode(5);
  n1->next = n2;
  // n2->next = n3;
  // n3->next = n4;
  // n4->next = n5;
  Solution s;
  auto re = s.reverseBetween(nullptr, 0, 0);
  s.printNode(re);
  return 0;
}
