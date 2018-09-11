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
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    do {
      result.push_back(nums);
    } while (next_permutation(nums.begin(), nums.end()));
    return result;
  }
};

int main(int argc, char const *argv[])
{
  Solution sln;

  vector<int> nums;
  nums.push_back(1);
  nums.push_back(1);
  nums.push_back(2);
  auto result = sln.permuteUnique(nums);
  cout << endl;
  for (auto i: result) {
    for (auto j: i) {
      cout << j << " ";
    }
    cout << endl;
  }
  return 0;
}