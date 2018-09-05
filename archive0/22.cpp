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
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n == 0) return result;
        if (n == 1) result.push_back("()");
        auto smallResult = generateParenthesis(n - 1);
        map<string, bool> hasExist;
        for(auto element: smallResult) {
          for (int i = 0; i <= element.length(); i ++) {
            auto newElement = string(element);
            newElement.insert(i, "()");
            if (!hasExist[newElement]) {
              hasExist[newElement] = true;
              result.push_back(newElement);
            }
          }
        }
        return result;
    }
};

int main() {
  auto sln = Solution();
  auto result = sln.generateParenthesis(3);
  for (auto ele: result) {
    cout << ele << endl;
  }
  cout << endl;
  result = sln.generateParenthesis(2);
  for (auto ele: result) {
    cout << ele << endl;
  }
  cout << endl;
  result = sln.generateParenthesis(1);
  for (auto ele: result) {
    cout << ele << endl;
  }
  cout << endl;
  result = sln.generateParenthesis(0);
  for (auto ele: result) {
    cout << ele << endl;
  }
  cout << endl;
  return 0;
}