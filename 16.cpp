#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
      int minDist = INT_MAX;
      int result;
      for (int i = 0; i < nums.size(); i ++) {
        for (int j = i + 1; j < nums.size(); j ++) {
          for (int k = j + 1; k < nums.size(); k ++) {
            int sum = nums[i] + nums[j] + nums[k];
            int dist = abs(sum - target);
            if (dist < minDist) {
              result = sum;
              minDist = dist;
              // cout << nums[i] << " " << nums[j] << " " << nums[k] << endl;
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
  s.push_back(-1);
  s.push_back(2);
  s.push_back(1);
  s.push_back(-4);
  auto sln = Solution();
  sln.threeSumClosest(s, 1);
  return 0;
}
