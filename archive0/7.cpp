#include <iostream>
#include <algorithm>

class Solution {
public:
    int reverse(int x) {
        int ret = _reverse(x);
        if (x % 10 == 0) {
            return ret;
        }
        int back = _reverse(ret);
        if (x != back) return 0;
        return ret;
    }

    int _reverse(int x) {
        int sign = x > 0 ? 1 : -1;
        int ret = 0;
        x = std::abs(x);
        while (x != 0) {
            int remainder = x % 10;
            x /= 10;
            ret = ret * 10;
            ret = ret + remainder * sign;
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
  auto sln = Solution();
  std::cout << sln.reverse(-120) << "\n";
  return 0;
}
