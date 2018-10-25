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

// class Solution {
// public:
//   int minimum(vector<vector<int>>& triangle, int start, int index) {
//     auto row = triangle[start];
//     int spend = row[index];
//     if (start == triangle.size() - 1) return spend;
//     int left = minimum(triangle, start + 1, index);
//     int right = minimum(triangle, start + 1, index + 1);
//     return spend + min(left, right);
//   }

//   int minimumTotal(vector<vector<int>>& triangle) {
//     if (triangle.size() == 0) return 0;
//     return minimum(triangle, 0, 0);
//   }
// };

class Solution {
public:

  int minimumTotal(vector<vector<int>>& triangle) {
    if (triangle.size() == 0) return 0;
    vector<int> res(triangle[0]);
    for (int i = 1; i < triangle.size(); i ++) {
      vector<int> temp;
      for (int j = 0; j < triangle[i].size(); j ++) {
        if (j == 0) {
          temp.push_back(res[j] + triangle[i][j]);
        } else if (j == triangle[i].size() - 1) {
          temp.push_back(res[j - 1] + triangle[i][j]);
        } else {
          temp.push_back(min(res[j - 1], res[j]) + triangle[i][j]);
        }
      }
      res = temp;
    }
    int mini = res[0];
    for (int i = 1; i < res.size(); i ++) {
      if (mini > res[i]) mini = res[i];
    }
    return mini;
  }
};