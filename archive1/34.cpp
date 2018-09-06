#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      vector<int> noResult;
      noResult.push_back(-1);
      noResult.push_back(-1);
      if (nums.size() == 0) return noResult;
      vector<int> result;
      auto low = lower_bound(nums.begin(), nums.end(), target);
      if (low == nums.end() || *low != target) {
        return noResult;
      }
      result.push_back(low - nums.begin());
      auto upper = upper_bound(nums.begin(), nums.end(), target);
      result.push_back(upper - nums.begin() - 1);
      return result;
    }
};

int main(int argc, char const *argv[])
{
  auto sln = Solution();

  vector<int> nums;
  nums.push_back(1);
  cout << *lower_bound(nums.begin(), nums.end(), 0) << endl;
  // auto result = sln.searchRange()
  return 0;
}
