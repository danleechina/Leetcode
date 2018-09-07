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
  string countAndSay(int n) {
    if (n == 1) return "1";
    auto smallResult = countAndSay(n - 1);
    string result;
    int count = 1;
    int value = smallResult[0] - '0';
    for (int i = 1; i < smallResult.size(); i ++) {
      auto element = smallResult[i] - '0';
      if (element == value) {
        count++;
        continue;
      } else {
        result.push_back(count + '0');
        result.push_back(value + '0');
        value = element;
        count = 1;
      }
    }
    result.push_back(count + '0');
    result.push_back(value + '0');
    return result;
  }
};

int main(int argc, char const *argv[])
{
  auto sln = Solution();
  cout << sln.countAndSay(1) << endl;
  cout << sln.countAndSay(2) << endl;
  cout << sln.countAndSay(3) << endl;
  cout << sln.countAndSay(4) << endl;
  cout << sln.countAndSay(5) << endl;
  cout << sln.countAndSay(6) << endl;
  cout << sln.countAndSay(7) << endl;
  return 0;
}
