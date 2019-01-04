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
  vector<string> findRepeatedDnaSequences(string s)
  {
    if (s.size() <= 10)
      return {};
    set<string> res;
    string tmp1, tmp2;
    for (int i = 0; i < s.size(); i++)
    {
      tmp1 = s.substr(i, 10);
      if (res.find(tmp1) != res.end())
      {
        continue;
      }
      for (int j = i + 1; j + 10 <= s.size(); j++)
      {
        tmp2 = s.substr(j, 10);
        if (tmp1.compare(tmp2) == 0)
        {
          res.insert(tmp1);
          break;
        }
      }
    }
    return vector<string>(res.begin(), res.end());
  }
};