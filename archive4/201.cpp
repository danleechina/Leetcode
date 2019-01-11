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
  int rangeBitwiseAnd(int m, int n)
  {
    if (m == n)
      return m;
    return rangeBitwiseAnd(m / 2, n / 2) << 1;
  }
};