#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
bool myfunction(int i, int j) { return (i < j); }

class Solution
{
public:
  bool isPalindrome(string s)
  {
    int i = 0, j = s.size() - 1;
    while (i < j)
    {
      if (s[i] != s[j])
        return false;
      i++;
      j--;
    }
    return true;
  }

  vector<vector<string>> partition(string s)
  {
    vector<vector<string>> res;
    if (s.size() == 1)
    {
      res.push_back({s});
      return res;
    }
    for (int i = 1; i <= s.size(); i++)
    {
      string tmp = s.substr(0, i);
      if (!isPalindrome(tmp))
        continue;
      if (i == s.size())
      {
        res.push_back({tmp});
      }
      auto smallerRes = partition(s.substr(i, s.size() - i));
      for (auto element : smallerRes)
      {
        element.insert(element.begin(), tmp);
        res.push_back(element);
      }
    }
    return res;
  }
};

int main(int argc, char const *argv[])
{
  Solution s;
  auto res = s.partition("aab");
  for (auto i : res)
  {
    for (auto j : i)
    {
      cout << j << ' ';
    }
    cout << endl;
  }
  return 0;
}
