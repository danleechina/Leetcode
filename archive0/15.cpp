#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

bool myfunction (int i,int j) { return (i<j); }
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        map<string, bool> hasExist;
        if (nums.size() < 3) return result;
        sort(nums.begin(), nums.end(), myfunction);
        auto low = lower_bound(nums.begin(), nums.end(), 0);
        auto upper = upper_bound(nums.begin(), nums.end(), 0);
        
        for (int i = 0; i < nums.size(); i ++) {
          for (int j = i + 1; j < nums.size(); j ++) {
            for (int k = j + 1; k < nums.size(); k ++) {
              if (nums[i] + nums[j] + nums[k] == 0) {
                vector<int> ele;
                ele.push_back(nums[i]);
                ele.push_back(nums[j]);
                ele.push_back(nums[k]);
                sort(ele.begin(), ele.end(), myfunction);
                string key;
                for (auto e: ele) {
                  key += to_string(e);
                }
                if (!hasExist[key]) {
                  result.push_back(ele);
                  hasExist[key] = true;
                }
              }
            }
          }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
  vector<int> s;
  s.push_back(1);
  s.push_back(1);
  s.push_back(1);
  auto sln = Solution();
  auto ret = sln.threeSum(s);
  for (auto e: ret) {
    for (auto ele: e) {
      cout << ele << " ";
    }
    cout << endl;
  }
  // cout << sln.threeSum(s) << endl;
  return 0;
}
