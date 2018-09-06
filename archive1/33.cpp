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

  int findMaxValueIndex(vector<int>& nums) {
    int start = 0;
    int end = nums.size();
    while (start < end) {
      int index = (end + start) / 2;
      if (nums[index] < nums[index - 1]) {
        start = end = index - 1;
      } else {
        if (nums.back() > nums[index]) {
          end = index;
        } else {
          start = index;
        }
      }
    }
    return start;
  }

  int search(vector<int>& nums, int target) {
    if (nums.size() == 0) return -1;
    int maxIndex = 0;
    if (nums.size() > 1) {
      if (nums.back() > nums.front()) maxIndex = nums.size() - 1;
      else maxIndex = findMaxValueIndex(nums);
    }
    if (target >= nums[0]) {
      int start = 0;
      int end = maxIndex + 1;
      while (start < end) {
        int index = (start + end)/2;
        if (nums[index] > target) {
          end = index;
        } else if (nums[index] < target) {
          start = index + 1;
        } else {
          return index;
        }
      }
    } else {
      int start = maxIndex + 1;
      int end = nums.size();
      while (start < end) {
        int index = (start + end)/2;
        if (nums[index] > target) {
          end = index;
        } else if (nums[index] < target) {
          start = index + 1;
        } else {
          return index;
        }
      }
    }
    return -1;
  }
};

int main() {
  auto sln = Solution();
  vector<int> p1;
  p1.push_back(4);
  p1.push_back(5);
  p1.push_back(6);
  p1.push_back(7);
  p1.push_back(0);
  p1.push_back(1);
  p1.push_back(2);

  // p1.push_back(7);
  // p1.push_back(8);
  // p1.push_back(1);
  // p1.push_back(2);
  // p1.push_back(3);
  // p1.push_back(4);
  // p1.push_back(5);
  // p1.push_back(6);

  cout << sln.search(p1, 4) << endl;
  cout << sln.search(p1, 5) << endl;
  cout << sln.search(p1, 6) << endl;
  cout << sln.search(p1, 7) << endl;
  cout << sln.search(p1, 0) << endl;
  cout << sln.search(p1, 1) << endl;
  cout << sln.search(p1, 2) << endl;
  cout << sln.search(p1, 3) << endl;

  p1.clear();
  cout << sln.search(p1, 0) << endl;

  p1.push_back(5);
  p1.push_back(8);
  cout << sln.search(p1, 5) << endl;
  cout << sln.search(p1, 8) << endl;
  cout << sln.search(p1, 0) << endl;
  return 0;
}