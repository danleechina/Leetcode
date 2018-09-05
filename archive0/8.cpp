#include <iostream>
#include <algorithm>
#include <string>

class Solution {
public:
    int myAtoi(std::string str) {
      auto trimedStr = trimString(str);
      int sign = getSign(trimedStr);
      auto trimedSignStr = trimSign(trimedStr);
      if (trimedSignStr.length() == 0) return 0;
      int start = 0;
      int result = 0;
      while (start < trimedSignStr.length()) {
        int remainder = trimedSignStr[start] - '0';
        if (remainder > 9 || remainder < 0) {
          break;
        }
        if (sign > 0) {
          if (result > INT_MAX/10 || (result == INT_MAX/10 && remainder > 7)) return INT_MAX;
        } else {
          int r = -result;
          if (r < INT_MIN/10 || (r == INT_MIN/10 && remainder > 8)) return INT_MIN;
        }
        result = 10 * result + remainder;
        start ++;
      }
      return result * sign;
    }

    std::string trimString(std::string str) {
      int start = 0;
      while(start < str.length() && str[start] == ' ') {
        start ++;
      }
      return str.substr(start, str.length() - start);
    }

    std::string trimSign(std::string str) {
      if (str.length() == 0) return "";
      if (str[0] == '-' || str[0] == '+') return str.substr(1, str.length() - 1);
      return str;
    }

    int getSign(std::string str) {
      if (str.length() == 0) return 1;
      if (str[0] == '-') return -1; 
      return 1;
    }
};

int main(int argc, char const *argv[])
{
  // std::string s = "ssss";
  // if (s[0] == 's') std::cout << "HELELEL";
  auto sln = Solution();
  std::cout << sln.myAtoi("42") << "\n";
  std::cout << sln.myAtoi("   -42") << "\n";
  std::cout << sln.myAtoi("4193 with words") << "\n";
  std::cout << sln.myAtoi("words and 987") << "\n";
  std::cout << sln.myAtoi("-91283472332") << "\n";
  return 0;
}
