#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
bool myfunction (int i,int j) { return (i<j); }

class Solution {
public:
  vector<vector<int>> combine(vector<int>& nums, int start, int end, int cnt) {
    vector<vector<int>> result;
    if (cnt == 0) {
      vector<int> empty;
      result.push_back(empty);
      return result;
    }

    if (cnt == 1) {
      for (int i = start; i <= end; i ++) {
        vector<int> a;
        a.push_back(nums[i]);
        result.push_back(a);
      }
      return result;
    }

    auto smallerResult = combine(nums, start + 1, end, cnt - 1);
    for (auto sr: smallerResult) {
      vector<int> nsr(sr);
      nsr.insert(nsr.begin(), nums[start]);
      result.push_back(nsr);
    }

    if (start + cnt <= end) {
      smallerResult = combine(nums, start + 1, end, cnt);
      for (auto sr: smallerResult) {
        result.push_back(sr);
      }
    }
    return result;
  }

  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    for (int i = 0; i <= nums.size(); i ++) {
      auto s = combine(nums, 0, nums.size() - 1, i);
      for (auto ss: s) result.push_back(ss);
    }
    return result;
  }
};