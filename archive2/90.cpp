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
  string keyFromVec(vector<int>& num) {
    string key = "";
    sort(num.begin(), num.end(), myfunction);
    for (auto ele: num) {
      key += to_string(ele);
      key += "#";
    }
    return key;
  }

  vector<vector<int>> combine(map<string, bool> visited, vector<int>& nums, int start, int end, int cnt) {
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

    auto smallerResult = combine(visited, nums, start + 1, end, cnt - 1);
    for (auto sr: smallerResult) {
      vector<int> nsr(sr);
      nsr.insert(nsr.begin(), nums[start]);
      result.push_back(nsr);
    }

    if (start + cnt <= end) {
      smallerResult = combine(visited, nums, start + 1, end, cnt);
      for (auto sr: smallerResult) {
        result.push_back(sr);
      }
    }
    return result;
  }

  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> result;
    map<string, bool> visited;
    for (int i = 0; i <= nums.size(); i ++) {
      auto s = combine(visited, nums, 0, nums.size() - 1, i);
      for (auto ss: s) result.push_back(ss);
    }
    for (auto it = result.begin(); it != result.end();) {
      auto key = keyFromVec(*it);
      if (visited[key]) result.erase(it);
      else {
        visited[key] = true;
        it ++;
      }
    }
    return result;
  }
};