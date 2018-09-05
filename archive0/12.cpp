#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::string intToRoman(int num) {
      std::string ret = "";
      while (num >= 1000) {
        num -= 1000;
        ret = ret + "M";
      }
      if (num >= 900) {
        ret = ret + "CM";
        num -= 900;
      }
      if (num >= 500) {
        ret = ret + "D";
        num -= 500;
      }
      if (num >= 400) {
        ret = ret + "CD";
        num -= 400;
      }
      while (num >= 100) {
        num -= 100;
        ret = ret + "C";
      }
      if (num >= 90) {
        num -= 90;
        ret = ret + "XC";
      }
      if (num >= 50) {
        num -= 50;
        ret = ret + "L";
      }
      if (num >= 40) {
        num -= 40;
        ret = ret + "XL";
      }
      while (num >= 10) {
        num -= 10;
        ret = ret + "X";
      }
      if (num >= 9) {
        num -= 9;
        ret = ret + "IX";
      }
      if (num >= 5) {
        num -= 5;
        ret = ret + "V";
      }
      if (num >= 4) {
        num -= 4;
        ret = ret + "IV";
      }
      while (num > 0) {
        num -= 1;
        ret = ret + "I";
      }
      return ret;
    }
};

int main(int argc, char const *argv[])
{
  auto sln = Solution();
  std::cout << sln.intToRoman(3) << std::endl;
  std::cout << sln.intToRoman(4) << std::endl;
  std::cout << sln.intToRoman(9) << std::endl;
  std::cout << sln.intToRoman(58) << std::endl;
  std::cout << sln.intToRoman(1994) << std::endl;
  return 0;
}
