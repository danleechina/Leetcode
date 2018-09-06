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
  bool isValidSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i ++) {
      map<char, int> isRowValid;
      for (int j = 0; j < 9; j ++) {
        auto rowElement = board[i][j];
        if (rowElement == '.') continue;
        if (isRowValid.find(rowElement) != isRowValid.end()) return false;
        else isRowValid[rowElement] = 1; 
      }
    }

    for (int i = 0; i < 9; i ++) {
      map<char, int> isColValid;
      for (int j = 0; j < 9; j ++) {
        auto colElement = board[j][i];
        if (colElement == '.') continue;
        if (isColValid.find(colElement) != isColValid.end()) return false;
        else isColValid[colElement] = 1;
      }
    }

    for (int i = 0; i < 3; i ++) {
      for (int j = 0; j < 3; j ++) {
        map<char, int> isBlockValid;
        for (int m = 0; m < 3; m ++) {
          for (int n = 0; n < 3; n ++) {
            auto blockElement = board[i + m][j + n];
            if (blockElement == '.') continue;
            if (isBlockValid.find(blockElement) != isBlockValid.end()) return false;
            else isBlockValid[blockElement] = 1;
          }
        }
      }
    }
    return true;
  }
};