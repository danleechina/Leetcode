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

  void printMatrix(vector<vector<int>>& matrix) {
    cout << endl;
    for (auto i: matrix) {
      for (auto j: i) {
        cout << j << " ";
      }
      cout << endl;
    }
  }

  void rotate(vector<vector<int>>& matrix) {
    if (matrix.size() == 0 || matrix.size() == 1) return;
    int n = matrix.size();
    for (int i = 0; i < (n + 1)/2; i ++) {
      for (int k = i; k < n - i - 1; k ++ ) {
        for (int j = 0; j < 3; j ++) {
          int tmp = matrix[i][k];
          if (j == 0) {
            matrix[i][k] = matrix[k][n - 1 - i];
            matrix[k][n - 1 - i] = tmp;
          } else if (j == 1) {
            matrix[i][k] = matrix[n - 1 - i][n - 1 - k];
            matrix[n - 1 - i][n - 1 - k] = tmp;
          } else if (j == 2) {
            matrix[i][k] = matrix[n - 1 - k][i];
            matrix[n - 1 - k][i] = tmp;
          } 
          printMatrix(matrix);
        }
      }
    }
  }
};