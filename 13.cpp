#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    int romanToInt(std::string s) {
      int index = 0;
      int result = 0;
      while (index < s.length()) {
        int nextIndex = index + 1;
        if (nextIndex < s.length()) {
          if (s[index] == 'C' && s[nextIndex] == 'D') {
            result += 400;
            index ++;
            continue;
          } else if (s[index] == 'C' && s[nextIndex] == 'M') {
            result += 900;
            index += 2;
            continue;
          } else if (s[index] == 'X' && s[nextIndex] == 'L') {
            result += 40;
            index += 2;
            continue;
          } else if (s[index] == 'X' && s[nextIndex] == 'C') {
            result += 90;
            index += 2;
            continue;
          } else if (s[index] == 'I' && s[nextIndex] == 'V') {
            result += 4;
            index += 2;
            continue;
          } else if (s[index] == 'I' && s[nextIndex] == 'X') {
            result += 9;
            index += 2;
            continue;
          }
        }
        if (s[index] == 'I') {
          result += 1;
        }
        if (s[index] == 'V') {
          result += 5;
        }
        if (s[index] == 'X') {
          result += 10;
        }
        if (s[index] == 'L') {
          result += 50;
        }
        if (s[index] == 'C') {
          result += 100;
        }
        if (s[index] == 'D') {
          result += 500;
        }
        if (s[index] == 'M') {
          result += 1000;
        }
        index ++;
      }
      return result;
    }
};

int main(int argc, char const *argv[])
{
  auto sln = Solution();
  std::cout << sln.romanToInt("III") << std::endl;
  std::cout << sln.romanToInt("IV") << std::endl;
  std::cout << sln.romanToInt("IX") << std::endl;
  std::cout << sln.romanToInt("LVIII") << std::endl;
  std::cout << sln.romanToInt("MCMXCIV") << std::endl;
  return 0;
}
