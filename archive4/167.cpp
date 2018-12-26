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
  int binaryFind(vector<int> &numbers, int target, int start, int end)
  {
    int res = -1;
    if (end < start)
      return res;
    while (start <= end)
    {
      int mid = (end + start) / 2;
      if (numbers[mid] == target)
        return mid;
      else if (numbers[mid] < target)
      {
        start = mid + 1;
      }
      else
      {
        end = mid - 1;
      }
    }
    return res;
  }

  vector<int> twoSum(vector<int> &numbers, int target)
  {
    for (int i = 0; i < numbers.size(); i++)
    {
      int need = target - numbers[i];
      int j = -1;
      if (need > numbers[i])
      {
        j = binaryFind(numbers, need, i + 1, numbers.size() - 1);
      }
      else
      {
        j = binaryFind(numbers, need, 0, i - 1);
      }
      if (j != -1)
      {
        if (i < j)
          return {i + 1, j + 1};
        else
          return {j + 1, i + 1};
      }
    }
    return {1, 1};
  }
};