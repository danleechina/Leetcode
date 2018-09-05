#include <iostream>
#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int max = 0;
        int start = 0;
        int end = height.size() - 1;
        while(start < end && end > 0 && start < height.size()) {
          max = std::max(max, (end - start) * std::min(height[end], height[start]));
          if (height[start] < height[end]) {
            start ++;
          } else {
            end --;
          }
        }
        return max;
    }
};

int main(int argc, char const *argv[])
{
  auto sln = Solution();
  int s[] = {1,2,4,3};
  std::vector<int> data(s, s + sizeof(s)/sizeof(int));
  std::cout << sln.maxArea(data) << std::endl;
  return 0;
}
