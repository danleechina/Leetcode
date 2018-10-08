#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
bool myfunction (int i,int j) { return (i<j); }

class Solution {
public:
  void insertByShift(vector<int>& nums, int value, int index) {
    int tmp = nums[index];
    nums[index] = value;
    for (int i = index + 1; i < nums.size(); i ++) {
      int old = nums[i];
      nums[i] = tmp;
      tmp = old;
    }
  }

  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int mIndex = 0;
    int currentSize = m;
    for (int i = 0; i < n; i ++) {
      while(mIndex < currentSize && nums2[i] > nums1[mIndex]) {
        mIndex ++;
      }
      insertByShift(nums1, nums2[i], mIndex);
      mIndex ++;
      currentSize ++;
    }
  }
};