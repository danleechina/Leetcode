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
bool myfunction (int i,int j) { return (i<j); }

  struct UndirectedGraphNode {
      int label;
      vector<UndirectedGraphNode *> neighbors;
      UndirectedGraphNode(int x) : label(x) {};
  };

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return nullptr;
        map<int, UndirectedGraphNode*> existedNode;
        UndirectedGraphNode *copiedNode = new UndirectedGraphNode(node->label);
        existedNode[node->label] = copiedNode;
        for (auto neighbor: node->neighbors) {
            copiedNode->neighbors.push_back(cloneGraph(neighbor, existedNode));
        }
        return copiedNode;
    }

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node, map<int, UndirectedGraphNode*> &existedNode) {

        if (!node) return nullptr;
        auto target = existedNode.find(node->label);
        if (target != existedNode.end()) return target->second;
        UndirectedGraphNode *copiedNode = new UndirectedGraphNode(node->label);
        existedNode[node->label] = copiedNode;
        for (auto neighbor: node->neighbors) {
            copiedNode->neighbors.push_back(cloneGraph(neighbor, existedNode));
        }
        return copiedNode;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    return 0;
}
