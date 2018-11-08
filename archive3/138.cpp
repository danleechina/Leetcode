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

struct RandomListNode
{
  int label;
  RandomListNode *next, *random;
  RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution
{
public:
  RandomListNode *copyRandomList(RandomListNode *head)
  {
    map<RandomListNode *, int> oldNodeToIndex;
    vector<RandomListNode *> newNodes;
    RandomListNode *newHead;
    RandomListNode *oldCur = head, *newCur = nullptr;
    for (int i = 0; oldCur != nullptr; i++, oldCur = oldCur->next)
    {
      RandomListNode *newNode = new RandomListNode(oldCur->label);
      if (newCur != nullptr)
      {
        newCur->next = newNode;
      }
      newCur = newNode;
      if (i == 0)
        newHead = newNode;
      oldNodeToIndex[oldCur] = i;
      newNodes.push_back(newNode);
    }
    newCur = newHead;
    oldCur = head;
    for (int i = 0; newCur != nullptr; i++, newCur = newCur->next, oldCur = oldCur->next)
    {
      if (oldCur->random)
      {
        int index = oldNodeToIndex[oldCur->random];
        newCur->random = newNodes[index];
      }
    }
    return newHead;
  }
};