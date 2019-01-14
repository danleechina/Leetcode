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
  bool isIsomorphic(string s, string t)
  {
    map<char, char> match1, match2;
    for (int i = 0; i < s.size(); i++)
    {
      auto si = s[i];
      auto ti = t[i];
      auto sii = match1.find(si);
      auto tii = match2.find(ti);
      if (sii != match1.end())
      {
        if (sii->second != ti)
          return false;
      }
      if (tii != match2.end())
      {
        if (tii->second != si)
          return false;
      }
      match1[si] = ti;
      match2[ti] = si;
    }
    return true;
  }
};