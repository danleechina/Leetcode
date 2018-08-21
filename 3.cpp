#include <string>
#include <vector>
#include <set>
#include <iostream>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
      std::set<char> info;
      int maxLength = 0;
      int start = 0;
      int end = 0;
      for(int index = 0; index + s.begin() != s.end(); index ++) {
        auto element = *(index + s.begin());
        auto it = info.find(element);
        if (it != info.end()) {
          maxLength = std::max(maxLength, end - start);
          auto tempStartElement = *(start + s.begin());
          while (tempStartElement != element) {
            info.erase(info.find(tempStartElement));
            start ++;
            tempStartElement = *(start + s.begin());
          }
          info.erase(it);
          info.insert(element);
          start ++;
        } else {
          info.insert(element);
        }
        end = index + 1;
      }
      return std::max(maxLength, end - start);
    }
};

int main() {
  auto sln = Solution();
  std::cout<< sln.lengthOfLongestSubstring("pwwkew") << '\n';
  return 0;
}