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
  bool isHappy(int n)
  {
    map<int, bool> visited;
    int sum = -1;
    while (true)
    {
      int t = n % 10;
      if (sum < 0)
      {
        sum = t * t;
      }
      else
      {
        sum += t * t;
      }
      n /= 10;
      if (n == 0)
      {
        if (sum == 1)
        {
          return true;
        }
        else if (visited.find(sum) != visited.end())
        {
          return false;
        }
        visited[sum] = true;
        n = sum;
        sum = -1;
      }
    }
  }
};