#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
bool myfunction (int i,int j) { return (i<j); }

class Solution {
public:
  string simplifyPath(string path) {
    stack<string> slashSeparatorStack;
    int startSlash = 0;
    for(int i = 0; i < path.size(); i ++) {
      if (path[i] == '/') {
        if (i == startSlash) continue;
        auto node = path.substr(startSlash, i - startSlash);
        slashSeparatorStack.push(node);
        startSlash = i;
      } else if (i == path.size() - 1) {
        auto node = path.substr(startSlash, path.size() - startSlash);
        slashSeparatorStack.push(node);
      }
      while(!slashSeparatorStack.empty() && slashSeparatorStack.top().compare("/") == 0) {
        slashSeparatorStack.pop();
      }
      while(!slashSeparatorStack.empty() && slashSeparatorStack.top().compare("/.") == 0) {
        slashSeparatorStack.pop();
      }
      int popCount = 0;
      while(!slashSeparatorStack.empty() && slashSeparatorStack.top().compare("/..") == 0) {
        slashSeparatorStack.pop();
        popCount ++;
      }
      while(!slashSeparatorStack.empty() && popCount > 0) {
        slashSeparatorStack.pop();
        popCount --;
      }
    }
    string result;
    while(!slashSeparatorStack.empty()) {
      auto top = slashSeparatorStack.top();
      slashSeparatorStack.pop();
      if (top.compare("/") == 0) continue;
      else result.insert(0, top);
    }
    if (result.size() == 0) return "/";
    return result;
  }
};