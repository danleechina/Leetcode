class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0) return 0;
        int result = 0;
        auto currentIndex = nums.begin();
        while(currentIndex != nums.end()) {
            if (*currentIndex == val) {
                nums.erase(currentIndex);
            } else {
                result ++;
                currentIndex ++;
            }
        }
        return result;
    }
};