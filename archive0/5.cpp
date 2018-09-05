#include <iostream>
#include <algorithm>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
      auto size = s.size();
      auto checkLength = size;
      while (checkLength > 0) {
        int start = 0;
        while(start + checkLength <= size) {
          bool isOk = true;
          int i = start;
          int j = checkLength + start - 1;
          for(; i <= j; i ++, j --) {
            if (s[i] != s[j]) {
              isOk = false;
              break;
            }
          }
          if (isOk) {
            return s.substr(start, checkLength);
          }
          start ++;
        }
        checkLength -= 1;
      }
      return "";
    }
};

int main(int argc, char const *argv[])
{
  auto sln = Solution();
  std::cout << sln.longestPalindrome("abbbc") << "\n";
  return 0;
}
