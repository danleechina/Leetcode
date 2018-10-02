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
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        auto start = nums.begin() + 1;
        int checkValue = nums[0];
        int cnt = 1;
        while (start != nums.end()) {
            if (*start == checkValue) {
                cnt ++;
                if (cnt > 2) {
                    cnt = 2;
                    nums.erase(start);
                } else {
                    start ++;
                }
            } else {
                cnt = 1;
                checkValue = *start;
                start ++;
            }
        }
        return nums.size();      
    }
};