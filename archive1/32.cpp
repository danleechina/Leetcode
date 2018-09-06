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
  int longestValidParentheses(string s) {
    vector<int> brackets;
    vector<int> bracketIndex;
    for (int i = 0; i < s.size(); i ++) {
      if (brackets.empty()) {
        brackets.push_back(s[i]);
        bracketIndex.push_back(i);
      } else if (s[i] == ')' && brackets.back() == '(') {
        brackets.erase(brackets.end() - 1);
        bracketIndex.erase(bracketIndex.end() - 1);
      } else {
        brackets.push_back(s[i]);
        bracketIndex.push_back(i);
      }
    }
    // for (auto e: bracketIndex) {
    //   cout << e << " ";
    // }
    // cout << endl;
    if (bracketIndex.empty()) return s.size();
    int result = bracketIndex[0];
    for (int i = 0; i < bracketIndex.size(); i ++) {
      if (i == bracketIndex.size() - 1) {
        int ss = s.length() - bracketIndex.back() - 1;
        result = max(result, ss);
      } else {
        result = max(bracketIndex[i + 1] - bracketIndex[i] - 1, result);
      }
    }
    return result;
  }
};

int main(int argc, char const *argv[])
{
  auto sln = Solution();
  
  cout << sln.longestValidParentheses("())") << " " << endl;//2
  cout << sln.longestValidParentheses("(()") << " " << endl;//2
  cout << sln.longestValidParentheses(")()())") << " " << endl;//4
  cout << sln.longestValidParentheses(")(((((()())()()))()(()))(") << " " << endl;//22
  cout << sln.longestValidParentheses("()(()") << " " << endl;//2
  
  return 0;
}
