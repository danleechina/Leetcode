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
    bool canJump(vector<int>& nums) {
        if (nums.size() == 0) return false;
        if (nums.size() == 1) return true;
        int currentMostFarDistant = nums[0];
        int currentCheckPlace = 0;

        for (int i = currentCheckPlace; i <= currentMostFarDistant; i ++) {
            int iMostFarDistant = nums[i] + i;
            currentMostFarDistant = max(currentMostFarDistant, iMostFarDistant);
            if (currentMostFarDistant >= nums.size() - 1) return true;
        }
        return currentMostFarDistant >= nums.size() - 1;
    }
};