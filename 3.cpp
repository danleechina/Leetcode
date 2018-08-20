#include <string>
#include <vector>
#include <iostream>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
      std::vector<int> info(52, -1);
      int maxLength = 0;
      for(int index = 0; index + s.begin() != s.end(); index ++) {
        auto ch = *(index + s.begin());
        if (ch >= 'a' && ch <= 'z') {
          
        }
      }
      return maxLength;
    }
};

int main() {
  return 0;
}