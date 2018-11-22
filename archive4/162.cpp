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
  int findPeakElement(vector<int> &nums)
  {
    int lastValue = INT_MIN;
    cout << lastValue << endl;
    for (int i = 0; i < nums.size() - 1; i++)
    {
      if ((nums[i] > lastValue || nums[i] == INT_MIN) && nums[i] > nums[i + 1])
      {
        return i;
      }
      else
      {
        lastValue = nums[i];
      }
    }
    return nums.size() - 1;
  }
};

int main(int argc, char const *argv[])
{
  Solution s;
  vector<int> n = {1, 2, 1, 3, 5, 6, 4};
  cout << n[s.findPeakElement(n)] << endl;
  return 0;
}
