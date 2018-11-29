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
  vector<vector<int>> fourSum(vector<int> &nums, int target)
  {
    vector<vector<int>> ret;
    if (nums.size() < 4)
      return ret;
    sort(nums.begin(), nums.end(), myfunction);
    for (int i = 0; i < nums.size() - 3; i++)
    {
      int target3 = target - nums[i];
      for (int j = i + 1; j < nums.size() - 2; j++)
      {
        int target2 = target3 - nums[j];
        int start = j + 1, end = nums.size() - 1;
        while (start < end)
        {
          if (nums[start] + nums[end] < target2)
            start++;
          else if (nums[start] + nums[end] > target2)
            end--;
          else
          {
            ret.push_back(vector<int>{nums[i], nums[j], nums[start], nums[end]});
            do
            {
              start++;
            } while (start < end && nums[start] == nums[start - 1]);
            do
            {
              end--;
            } while (end > start && nums[end] == nums[end + 1]);
          }
        }
        while (j < nums.size() - 1 && nums[j] == nums[j + 1])
          j++;
      }
      while (i < nums.size() - 1 && nums[i] == nums[i + 1])
        i++;
    }
    return ret;
  }
};