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
    int singleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), myfunction);
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (res == nums[i])
            {
                res = nums[i + 1];
                i++;
            }
            else
            {
                return res;
            }
        }
        return res;
    }
};