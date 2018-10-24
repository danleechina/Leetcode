#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;
bool myfunction (int i,int j) { return (i<j); }

class Solution {
public:
  vector<int> getRow(int rowIndex) {
    return generate(rowIndex + 1).back();
  }
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    if (numRows <= 0) return res;
    vector<int> e = {1};
    res.push_back(e);
    for (int i = 2; i <= numRows; i ++) {
      vector<int> e;
      for (int j = 0; j < i; j ++) {
        int element = 0;
        if (j < i - 1) element = res[i - 2][j];
        if (j > 0) element += res[i - 2][j - 1];
        e.push_back(element);
      }
      res.push_back(e);
    }
    return res;
  }
};