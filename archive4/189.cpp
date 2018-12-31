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
    void shift(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return;
        int last = nums.back();
        for (int i = nums.size() - 1; i >= 1; i--)
        {
            nums[i] = nums[i - 1];
        }
        nums[0] = last;
    }

    void reverse(vector<int> &nums, int start, int end)
    {
        int length = end - start + 1;
        for (int i = 0; i < length / 2; i++)
        {
            int tmp = nums[i + start];
            nums[start + i] = nums[end - i];
            nums[end - i] = tmp;
        }
    }

    void printVI(vector<int> &nums)
    {
        for (auto e : nums)
        {
            cout << e << " ";
        }
        cout << endl;
    }

    void rotate(vector<int> &nums, int k)
    {
        k = k % nums.size();
        if (k == 0)
            return;
        reverse(nums, 0, nums.size() - 1);
        // printVI(nums);
        reverse(nums, 0, k - 1);
        // printVI(nums);
        reverse(nums, k, nums.size() - 1);
        // printVI(nums);
    }
};