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
  void sortColors(vector<int>& nums) {
    int zcnt = 0, ocnt = 0, tcnt = 0;
    for (int i = 0; i < nums.size(); i ++) {
      if (nums[i] == 0) zcnt ++;
      else if (nums[i] == 1) ocnt ++;
      else tcnt ++;
    }
    int i = 0;
    int pos = 0;
    while (i < zcnt) nums[pos] = 0, i ++, pos ++;
    i = 0;
    while (i < ocnt) nums[pos] = 1, i ++, pos ++;
    i = 0;
    while (i < tcnt) nums[pos] = 2, i ++, pos ++;
  }
};