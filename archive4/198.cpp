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
  int rob(vector<int> &nums)
  {
    int size = nums.size();
    if (size == 0)
      return 0;
    int best[size + 1];
    bool stepin[size + 1];
    best[0] = 0;
    stepin[0] = false;
    for (int i = 0; i < size; i++)
    {
      if (!stepin[i] || i == 0)
      {
        best[i + 1] = best[i] + nums[i];
        stepin[i + 1] = true;
      }
      else
      {
        if (nums[i] + best[i - 1] > best[i])
        {
          best[i + 1] = best[i - 1] + nums[i];
          stepin[i + 1] = true;
        }
        else
        {
          best[i + 1] = best[i];
          stepin[i + 1] = false;
        }
      }
    }
    // for (int i = 0; i < size; i++)
    // {
    //   cout << best[i + 1] << ' ' << stepin[i + 1] << endl;
    // }
    return best[size];
  }
};