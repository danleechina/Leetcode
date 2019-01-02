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
  string largestNumber(vector<int> &nums)
  {
    int i = 0;
    for (i = 0; i < nums.size(); i++)
    {
      if (nums[i] != 0)
        break;
    }
    if (i >= nums.size())
      return "0";

    vector<string> ns;
    for (auto n : nums)
    {
      ns.push_back(to_string(n));
    }
    sort(ns.begin(), ns.end(), [&](string l, string r) {
      return l + r > r + l;
    });
    string res;
    for (auto s : ns)
    {
      res += s;
    }
    return res;
  }
};