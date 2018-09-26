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
  void setZeroes(vector<vector<int>>& matrix) {
    set<int> needResetRow, needResetCol;
    for (int row = 0; row < matrix.size(); row ++) {
      auto rowInfo = matrix[row];
      for (int col = 0; col < rowInfo.size(); col ++) {
        if (rowInfo[col] == 0) {
          needResetCol.insert(col);
          needResetRow.insert(row);
        }
      }
    }
    for (auto row: needResetRow) {
      for (int i = 0; i < matrix[row].size(); i ++) {
        matrix[row][i] = 0;
      }
    }
    for (auto col: needResetCol) {
      for (int i = 0; i < matrix.size(); i ++) {
        matrix[i][col] = 0;
      }
    }
  }
};