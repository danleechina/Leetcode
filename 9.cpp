#include <iostream>
#include <algorithm>
#include <string>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        std::string s = std::to_string(x);
        int start = 0;
        while (start < s.length()/2) {
          if (s[start] != s[s.length() - start - 1]) return false;
          start ++;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
  auto sln = Solution();
  std::cout << sln.isPalindrome(121);
  std::cout << sln.isPalindrome(10);
  return 0;
}
