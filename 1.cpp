#include <algorithm>    // std::sort
#include <vector>       // std::vector

bool myfunction (int i,int j) { return (i<j); }

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        auto sortedNums(nums);
        std::sort(sortedNums.begin(), sortedNums.end(), myfunction);
        int elementOne;
        int elementTwo;
        for(auto start = sortedNums.begin(); start != sortedNums.end(); start ++) {
          elementOne = *start;
          elementTwo = target - elementOne;
          auto low = std::lower_bound(start, sortedNums.end(), elementTwo);
          if (*low == elementTwo) {
            break;
          }
        }

        int elementOneIndex = 0;
        int elementTwoIndex = 1;
        auto start = nums.begin();
        for(int index = 0; index + start != nums.end(); index ++) {
            if (*(start + index) == elementOne) {
              elementOneIndex = index;
            }
        }
        for(int index = 0; index + start != nums.end(); index ++) {
            if (*(start + index) == elementTwo && index != elementOneIndex) {
              elementTwoIndex = index;
            }
        }

        std::vector<int> ret;
        ret.push_back(std::min(elementTwoIndex, elementOneIndex));
        ret.push_back(std::max(elementTwoIndex, elementOneIndex));
        return ret;
    }
};

int main() {
  int numsIntArray[] = {3,3};
  std::vector<int> nums(numsIntArray, numsIntArray + sizeof(numsIntArray) / sizeof(int) );

  auto sol = Solution();
  auto result = sol.twoSum(nums, 6);
  printf("Result:\n");
  for (auto ele: result) {
    printf("%d\n", ele);
  }
  return 0;
}