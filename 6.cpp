#include <iostream>
#include <algorithm>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
      if (numRows == 1) return s;
      int segmentSize = 2 * numRows - 2;
      int segmentCount = s.size() / segmentSize;
      if (s.size() % segmentSize != 0) {
        segmentCount += 1;
      }
      std::string result;
      for (int row = 0; row < numRows; row ++) {
        for(int segment = 0; segment < segmentCount; segment ++) {
          for(int index = 0; index < 2; index ++) {
            if (index == 0) {
              int elementIndex = segment * segmentSize + row;
              if (elementIndex < s.size()) {
                result.push_back(s[elementIndex]);
              }
              if (row == 0 || row == numRows - 1) {
                break;
              }
            } else {
              int elementIndex = (segment + 1) * segmentSize - row;
              if (elementIndex < s.size()) {
                result.push_back(s[elementIndex]);
              }
            }
          }
        }
      }
      return result;
    }
};

int main(int argc, char const *argv[])
{
  auto sln = Solution();
  std::cout << sln.convert("", 3) << "\n";
  return 0;
}