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
  string convertToTitle(int n)
  {
    string res;
    while (n > 0)
    {
      n -= 1;
      res.insert(res.begin(), 'A' + n % 26);
      n = n / 26;
    }
    return res;
  }
};