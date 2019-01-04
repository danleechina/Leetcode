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
    vector<string> res;
    map<string, int> helper;
    string tmp;
    for (int i = 0; i < s.size(); i++)
    {
      tmp = s.substr(i, 10);
      if (helper[tmp] == 1)
      {
        res.push_back(tmp);
      }
      helper[tmp]++;
    }
    return res;
  }
};