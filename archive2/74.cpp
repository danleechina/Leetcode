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

class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m == 0) return false;
    int n = matrix[0].size();
    int start = 0, end = m * n - 1;
    while (start <= end) {
      int mid = (start + end) / 2;
      int row = mid / n;
      int col = mid - row * n;
      if (matrix[row][col] == target) return true;
      else if (matrix[row][col] < target) start = mid + 1;
      else end = mid - 1;
    }
    return false;
  }
};