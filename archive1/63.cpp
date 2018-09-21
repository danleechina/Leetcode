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
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    if (m == 0) return 0;
    int n = obstacleGrid[0].size();
    vector<vector<int>> smallerResult(m, vector<int>(n, 0));
    for (int i = 0; i < m; i ++) {
      for (int j = 0; j < n; j ++) {
        if (obstacleGrid[i][j] == 1) {
          smallerResult[i][j] = 0;
        } else {
          if (i == 0 && j == 0) {
            smallerResult[i][j] = 1;
          } else if (i == 0 || j == 0) {
            if (i == 0) smallerResult[i][j] = smallerResult[i][j - 1];
            if (j == 0) smallerResult[i][j] = smallerResult[i - 1][j];
          } else {
            smallerResult[i][j] = smallerResult[i - 1][j] + smallerResult[i][j -1];
          }
        }
      }
    }
    return smallerResult[m - 1][n - 1];
  }
};