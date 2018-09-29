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
  vector<vector<int>> combine(int start, int end, int cnt) {
    vector<vector<int>> result;
    if (cnt == 0) return result;
    if (cnt == 1) {
      for (int i = start; i <= end; i ++) {
        vector<int> a;
        a.push_back(i);
        result.push_back(a);
      }
      return result;
    }
    auto smallerResult = combine(start + 1, end, cnt - 1);
    for (auto sr: smallerResult) {
      vector<int> nsr(sr);
      nsr.insert(nsr.begin(), start);
      result.push_back(nsr);
    }
    if (start + cnt <= end) {
      smallerResult = combine(start + 1, end, cnt);
      for (auto sr: smallerResult) {
        result.push_back(sr);
      }
    }
    return result;
  }

  vector<vector<int>> combine(int n, int k) {
    if (k > n || k == 0) {
      vector<vector<int>> result;
      return result;
    }
    return combine(1, n, k > n ? n : k); 
  }
};