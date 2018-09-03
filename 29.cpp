#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
      if (divisor == INT_MIN) return 0;
      if (divisor == dividend) return 1;
      bool sign = true;
      if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) sign = false;
      if (divisor == 1) return dividend;
      if (divisor == -1) {
        if (sign) {
          if (dividend == INT_MIN) return INT_MAX;
          else return 0 - dividend;
        } else {
          return 0 - dividend;
        }
      }
      auto isNeedOne = false;
      if (dividend == INT_MIN) {
        dividend = INT_MAX;
        isNeedOne = true;
      }
      else dividend = abs(dividend);
      divisor = abs(divisor);
      auto backupDivisor = divisor;
      if (dividend < divisor) {
        return 0;
      }
      int result = 1;
      int oldDivisor = 0;
      while (oldDivisor < (divisor << 1) && (divisor << 1) <= dividend) {
        oldDivisor = divisor;
        divisor <<= 1;
        result <<= 1;
      }
      if (isNeedOne) {
        result += divide(dividend - divisor + 1, backupDivisor);
      } else {
        result += divide(dividend - divisor, backupDivisor);
      }
      if (sign) return result;
      else return 0 - result;
    }
};

int main(int argc, char const *argv[])
{
  auto sln = Solution();
  // cout << sln.divide(10, 3) << endl;
  // cout << sln.divide(7, -3) << endl;
  // cout << sln.divide(7, 7) << endl;
  // cout << sln.divide(-2147483648, -1) << endl;// 2147483647
  // cout << sln.divide(2147483647, 3) << endl; //715827882
  // cout << sln.divide(-1010369383, -2147483648) << endl;
  cout << sln.divide(-2147483648, -2147483648) << endl;// -1073741824
  return 0;
}
