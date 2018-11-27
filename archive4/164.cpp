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
  int maximumGap(vector<int> &nums)
  {
    int cnt = nums.size();
    if (cnt < 2)
      return 0;
    auto mm = minmax_element(nums.begin(), nums.end());
    int mi = *mm.first, ma = *mm.second;
    int gap = max((ma - mi) / (cnt - 1), 1);
    int m = (ma - mi) / gap + 1;
    vector<int> bucketMax(m, INT_MIN);
    vector<int> bucketMin(m, INT_MAX);
    for (int num : nums)
    {
      int bucket = (num - mi) / gap;
      if (num > bucketMax[bucket])
        bucketMax[bucket] = num;
      if (num < bucketMin[bucket])
        bucketMin[bucket] = num;
    }
    gap = bucketMax[0] - bucketMin[0];
    int i = 0, j;
    while (i < m)
    {
      j = i + 1;
      while (j < m && bucketMax[j] == INT_MIN && bucketMin[j] == INT_MAX)
        j++;
      if (j == m)
        break;
      gap = max(gap, bucketMin[j] - bucketMax[i]);
      i = j;
    }
    return gap;
  }
};

int main(int argc, char const *argv[])
{
  Solution s;
  vector<int> n = {1, 3, 4, 5, 6};
  cout << s.maximumGap(n);
  return 0;
}
