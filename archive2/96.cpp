#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
bool myfunction (int i,int j) { return (i<j); }

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int generateTrees(int minValue, int maxValue) {
        int total = 0;
        for (int i = minValue; i <= maxValue; i ++) {
            int leftResult = generateTrees(minValue, i - 1);
            int rightResult = generateTrees(i + 1, maxValue);
            if (leftResult == 0) {
                total += (rightResult == 0 ? 1 : rightResult);
            } else if (rightResult == 0) {
                total += (leftResult == 0 ? 1 : leftResult);
            } else {
                total += leftResult * rightResult;
            }
        }
        return total;
    }

    int numTrees(int n) {
        cout << INT_MAX;
        if (n == 0) return 1;
        int result = generateTrees(1, n);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto res = s.numTrees(3);
    cout << res << endl;
    return 0;
}
