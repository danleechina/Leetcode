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
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        vector<vector<int>> smallResult(m, vector<int>(n, 0));
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (i == 0 && j == 0) {
                    smallResult[i][j] = grid[i][j];
                } else if (i == 0 || j == 0) {
                    if (i == 0) {
                        smallResult[i][j] = smallResult[i][j - 1] + grid[i][j];
                    } else {
                        smallResult[i][j] = smallResult[i - 1][j] + grid[i][j];
                    }
                } else {
                    int tmp = smallResult[i - 1][j] + grid[i][j];
                    int tmp2 = smallResult[i][j - 1] + grid[i][j];
                    smallResult[i][j] = min(tmp, tmp2);
                }
            }
        }
        return smallResult[m - 1][n - 1];
    }
};