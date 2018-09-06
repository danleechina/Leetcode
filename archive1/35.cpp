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
  int searchInsert(vector<int>& nums, int target) {
    if (nums.size() == 0) return 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == target) return i;
      if (nums[i] > target) return i;
    }
    return nums.size();
  }
};

// int main(int argc, char const *argv[])
// {
//   auto sln = Solution();
//   vector<int> nums;
//   nums.push_back(1);
//   nums.push_back(3);
//   nums.push_back(5);
//   nums.push_back(6);
//   cout << sln.searchInsert(nums, 5) << endl;// 2
//   cout << sln.searchInsert(nums, 2) << endl;// 1
//   cout << sln.searchInsert(nums, 7) << endl;// 4
//   cout << sln.searchInsert(nums, 0) << endl;// 0
//   cout << sln.searchInsert(nums, 6) << endl;// 3
//   return 0;
// }
