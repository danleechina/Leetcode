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

class Solution
{
public:
  bool wordBreak(string s, vector<string> &wordDict)
  {
    set<string> dictionary(wordDict.begin(), wordDict.end());
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (int i = 1; i <= s.size(); i++)
    {
      for (int j = i - 1; j >= 0; j--)
      {
        if (dp[j])
        {
          auto subs = s.substr(j, i - j);
          if (dictionary.find(subs) != dictionary.end())
          {
            dp[i] = true;
            break;
          }
        }
      }
    }
    return dp[s.size()];
  }
};

int main(int argc, char const *argv[])
{
  Solution s;
  vector<string> wordDict = {"leet", "code"};
  s.wordBreak("leetcode", wordDict);
  return 0;
}
