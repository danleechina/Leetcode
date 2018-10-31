#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
bool myfunction(int i, int j) { return (i < j); }

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
  int sumNumbers(TreeNode *root)
  {
    int res = 0;
    if (!root)
      return res;
    vector<int> nums;
    sumNumbers(root, nums, res);
    return res;
  }

  void sumNumbers(TreeNode *root, vector<int> &nums, int &res)
  {
    nums.push_back(root->val);
    if (root->left)
      sumNumbers(root->left, nums, res);
    if (root->right)
      sumNumbers(root->right, nums, res);
    if (!root->left && !root->right)
      res += vectorIntToInt(nums);
    nums.pop_back();
  }

  int vectorIntToInt(vector<int> &nums)
  {
    int v = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      v *= 10;
      v += nums[i];
    }
    return v;
  }
};

int main(int argc, char const *argv[])
{
  Solution s;
  TreeNode *r = new TreeNode(1);
  r->left = new TreeNode(2);
  r->right = new TreeNode(3);
  cout << s.sumNumbers(r) << endl;
  return 0;
}
