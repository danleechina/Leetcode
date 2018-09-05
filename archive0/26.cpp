class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return 1;
        int length = 1;
        auto preValue = nums[0];
        auto begin = nums.begin() + 1;
        while (begin != nums.end()) {
            if (*begin == preValue) {
                nums.erase(begin);
            } else {
                preValue = *begin;
                begin ++;
                length ++;
            }
        }
        return length;
    }
};