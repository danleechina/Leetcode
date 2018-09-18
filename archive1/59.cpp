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
  int start = 1;

  void solve(int x1, int y1, int x2, int y2, vector<vector<int>> &matrix) {
    if (x1 < x2 && y1 < y2) {
      int i = x1, j = y1;
      for (; j < y2; j ++) {
        matrix[i][j] = start;
        start ++;
      }

      for (; i < x2; i ++) {
        matrix[i][j] = start;
        start ++;
      }

      for (; j > y1; j --) {
        matrix[i][j] = start;
        start ++;
      }

      for (; i > x1; i --) {
        matrix[i][j] = start;
        start ++;
      }
    } else if (x1 == x2 && y1 == y2) {
        matrix[x1][y2] = start;
    } else if (y1 == y2) {
      int i = x1, j = y1;
      for (; i < x2; i ++) {
        matrix[i][j] = start;
        start ++;
      }
    }
  }

  vector<vector<int>> generateMatrix(int n) {
    start = 1;
    vector<vector<int>> result;
    for (int i = 0; i < n; i ++) {
      vector<int> element(n, 1);
      result.push_back(element);
    }
    int x1 = 0, y1 = 0, x2 = n - 1, y2 = n - 1;
    while(x1 <= x2 && y1 <= y2) {
      solve(x1, y1, x2, y2, result);
      x1 ++, y1 ++, x2 --, y2 --;
    }
    return result;
  }
};

int main(int argc, char const *argv[])
{
  Solution sln;
  auto r = sln.generateMatrix(3);
  for (auto i: r) {
    for (auto j: i) {
      cout << j << "\t";
    }
    cout << endl;
  }
  cout << sln.start << endl;
  return 0;
}
