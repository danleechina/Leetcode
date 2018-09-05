#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    double findKthSmallestElement(int k, std::vector<int>& nums1, std::vector<int>::iterator start1, std::vector<int>::iterator end1, std::vector<int>& nums2, std::vector<int>::iterator start2, std::vector<int>::iterator end2) {
      if (k == 1) {
        auto value1 = *start1;
        auto value2 = *start2;
        if (start1 == end1) {
          return value2;
        }
        if (start2 == end2) {
          return value1;
        }
        return std::min(value2, value1);
      }
      if (start1 == end1) {
        return *(start2 + k - 1);
      }
      if (start2 == end2) {
        return *(start1 + k - 1);
      }
      if (*(end1 - 1) <= *start2) {
        if (k <= end1 - start1) {
          return *(start1 + k - 1);
        } else {
          return *(start2 + k - (end1 - start1) - 1);
        }
      }
      if (*(end2 - 1) <= *start1) {
        if (k <= end2 - start2) {
          return *(start2 + k - 1);
        } else {
          return *(start1 + k - (end2 - start2) - 1);
        }
      }

      double midValue1 = calculateMidValue(nums1, start1, end1);
      auto low2 = std::lower_bound(start2, end2, midValue1);
      auto count2 = low2 - start2;
      auto count1 = (end1 - start1) / 2;
      if ((end1 - start1) % 2 == 1) {
        count1 ++;
      }
      auto leftCount = count1 + count2;
      auto newStart1 = start1;
      auto newStart2 = start2;
      auto newEnd1 = start1 + (end1 - start1)/2 + 1;
      if ((end1 - start1) % 2 == 0) {
        newEnd1 = start1 + (end1 - start1)/2;
      }
      auto newEnd2 = low2;
      auto newK = k;
      if (leftCount < k) {
        newStart1 = start1 + (end1 - start1)/2 + 1;
        if ((end1 - start1) % 2 == 0) {
          newStart1 = start1 + (end1 - start1)/2;
        }
        newStart2 = low2;
        newEnd1 = end1;
        newEnd2 = end2;
        newK = k - leftCount;
      }
      return findKthSmallestElement(newK, nums1, newStart1, newEnd1, nums2, newStart2, newEnd2);
    }

    double calculateMidValue(std::vector<int>& nums, std::vector<int>::iterator start, std::vector<int>::iterator end) {
      auto size = end - start;
      auto v1 = *(size/2 + start);
      if (size % 2 == 0) {
        auto v2 = *(size/2 - 1 + start);
        return (v1 + v2)/2.0;
      }
      return v1;
    }

    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
      auto n1 = nums1.size();
      auto n2 = nums2.size();
      if (n1 == 0) {
        return calculateMidValue(nums2, nums2.begin(), nums2.end());
      }
      if (n2 == 0) {
        return calculateMidValue(nums1, nums1.begin(), nums1.end());
      }
      auto totalCount = n1 + n2;
      auto v1 = findKthSmallestElement(totalCount/2 + 1, nums1, nums1.begin(), nums1.end(), nums2, nums2.begin(), nums2.end());
      if (totalCount % 2 == 0) {
        auto v2 = findKthSmallestElement(totalCount/2, nums1, nums1.begin(), nums1.end(), nums2, nums2.begin(), nums2.end());
        return (v1 + v2)/2.0;
      }
      return v1;
    }
};

int main() {
  int nums1[] = {1, 2};
  std::vector<int> nums1Vector(nums1, nums1 + sizeof(nums1) / sizeof(int));
  int nums2[] = {3, 4, 9};
  std::vector<int> nums2Vector(nums2, nums2 + sizeof(nums2) / sizeof(int));
  auto sln = Solution();
  std::cout << sln.findMedianSortedArrays(nums1Vector, nums2Vector) << "\n";
  return 0;
}