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
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
  {
    vector<int> remain(gas);
    for (int i = 0; i < gas.size(); i++)
    {
      remain[i] -= cost[i];
    }
    for (int i = 0; i < remain.size(); i++)
    {
      if (remain[i] >= 0)
      {
        int rem = 0;
        int j = i;
        for (int cnt = 0; cnt < remain.size(); cnt++)
        {
          rem += remain[j];
          if (rem < 0)
            break;
          j = (j + 1) % remain.size();
        }
        if (rem >= 0)
          return i;
      }
    }
    return -1;
  }
};