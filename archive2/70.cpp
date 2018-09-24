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

    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        vector<int> smallResult(n, 1);
        smallResult[1] = 2;
        for (int i = 2; i < n; i ++) {
            smallResult[i] = smallResult[i - 2] + smallResult[i - 1] + 1;
        }
        for (auto s: smallResult) cout << s << " ";
        return smallResult[n - 2] + 1;
    }
};