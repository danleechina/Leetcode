#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

bool myfunction (int i,int j) { return (i<j); }

class Solution {
public:
  double myPow(double x, int n) {
    if (n == 0) return 1;
    bool needChange = n < 0;
    bool needOnceMore = n == INT_MIN;
    if (n == INT_MIN) n = INT_MAX;
    else if (needChange) n = -n;

    auto smallResult = myPow(x, n/2);
    double result = smallResult * smallResult;
    if (n % 2 == 1) result *= x;
    if (needOnceMore) result *= x;
    if (result == 0) return 0;
    if (needChange) result = 1/result;
    return result;
  }
};