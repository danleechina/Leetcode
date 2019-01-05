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
  int hammingWeight(uint32_t n)
  {
    int res = 0;
    for (int i = 0; i < 32; i++)
    {
      if (n & 1)
        res++;
      n >>= 1;
    }
    return res;
  }
};