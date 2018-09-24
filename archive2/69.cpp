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
    int mySqrt(int x) {
        int start = 0, end = x, mid;
        while (start <= x && start <= end) {
            double tmp = start;
            tmp += end;
            mid = tmp / 2.0;
            tmp = (double)mid * (double)mid;
            if (tmp > INT_MAX) {
                end = mid - 1;
                continue;
            }

            if (((int)tmp) < x) {
                start = mid + 1;
            } else if (((int)tmp) > x) {
                end = mid - 1;
            } else {
                return mid;
            }
        }
        double tmp = start;
        tmp += end;
        return tmp / 2.0;
    }
};