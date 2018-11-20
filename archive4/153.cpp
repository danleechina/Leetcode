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
  int findMin(vector<int> &nums)
  {
    if (nums.size() == 1)
      return nums[0];
    int start = 0;
    int end = nums.size() - 1;
    int mid = (start + end) / 2;
    while (start <= end)
    {
      if (nums[start] < nums[end])
      {
        if (nums[start] < nums.back())
        {
          return nums[start];
        }
      }
      if (nums[mid] > nums[start])
      {
        start = mid + 1;
      }
      else if (nums[mid] < nums[end])
      {
        end = mid;
      }
      else
      {
        return min(min(nums[mid], nums[end]), nums[start]);
      }
      mid = (start + end) / 2;
    }
    return nums[mid];
  }
};

int main(int argc, char const *argv[])
{
  Solution s;
  vector<int> n = {4, 5, 6, 7, 0, 1, 2};
  // vector<int> n = {3, 4, 5, 1, 2};
  // vector<int> n = {
  //     3,
  //     4,
  //     5,
  //     6,
  //     7,
  //     8,
  //     9,
  //     10,
  //     11,
  //     12,
  //     1,
  //     2,
  // };
  cout << s.findMin(n) << endl;
  return 0;
}
