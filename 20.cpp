#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
      stack<char> leftContainers;
      for (int i = 0; i < s.length(); i ++) {
        if (s[i] == ')') {
          if (!leftContainers.empty()) {
            auto topChar = leftContainers.top();
            leftContainers.pop();
            if (topChar == '(') continue;
            else return false;
          } else {
            return false;
          }
        } else if (s[i] == '}') {
          if (!leftContainers.empty()) {
            auto topChar = leftContainers.top();
            leftContainers.pop();
            if (topChar == '{') continue;
            else return false;
          } else {
            return false;
          }
        } else if (s[i] == ']') {
          if (!leftContainers.empty()) {
            auto topChar = leftContainers.top();
            leftContainers.pop();
            if (topChar == '[') continue;
            else return false;
          } else {
            return false;
          }
        } else {
          leftContainers.push(s[i]);
        }
      }
      return leftContainers.empty();
    }
};

int main(int argc, char const *argv[])
{
  auto sln = Solution();
  cout << sln.isValid("(((") << endl;
  return 0;
}
