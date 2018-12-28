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
  int majorityElement(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    int size = nums.size();
    int cnt = 1;
    int current = nums[0];
    for (int i = 1; i < size; i++)
    {
      if (cnt > size / 2)
        return current;
      else if (nums[i] != current)
      {
        current = nums[i];
        cnt = 1;
      }
      else
      {
        cnt++;
      }
    }
    return current;
  }
};