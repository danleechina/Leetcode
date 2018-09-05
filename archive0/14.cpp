#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
      if (strs.size() == 0) return "";
      if (strs.size() == 1) return strs[0];
      if (strs[0].compare("") == 0) return "";

      std::string firstStr = strs[0];
      int commonStrEnd = 0;
      while(commonStrEnd < firstStr.length()) {
        bool isOk = true;
        for (int index = 1; index < strs.size(); index ++) {
          auto str = strs[index];
          if (commonStrEnd < str.length() && str[commonStrEnd] == firstStr[commonStrEnd]) {

          } else {
            isOk = false;
            break;
          }
        }
        if (isOk) {
          commonStrEnd ++;
        } else {
          break;
        }
      }
      return firstStr.substr(0, commonStrEnd);
    }
};

int main(int argc, char const *argv[])
{
  std::vector<std::string> s;
  s.push_back("xxx");//["flower","flow","flight"]
  s.push_back("flcccow");
  s.push_back("flqqight");
  auto sln = Solution();
  std::cout << sln.longestCommonPrefix(s) << std::endl;
  return 0;
}
