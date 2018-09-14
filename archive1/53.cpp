#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

bool myfunction (int i,int j) { return (i<j); }

class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int gmaxValue = nums[0];
    for (int i = 0; i < nums.size(); i ++) {
      int maxValue = nums[i];
      int sum = nums[i];
      for (int j = i + 1; j < nums.size(); j ++) {
        sum += nums[j];
        maxValue = max(maxValue, sum);
      }
      gmaxValue = max(gmaxValue, maxValue);
    }
    return gmaxValue;
  }
};

int main(int argc, char const *argv[])
{
  Solution sln;

  vector<int> nums;
  nums.push_back(-1);
  nums.push_back(1);
  nums.push_back(-2);
  nums.push_back(3);


  // nums.push_back(16);
  // nums.push_back(-6);
  // nums.push_back(13);
  // nums.push_back(-14);
  // nums.push_back(5);
  // nums.push_back(-2);
  // nums.push_back(21);
  
  cout << sln.maxSubArray(nums) << endl;
  return 0;
}
