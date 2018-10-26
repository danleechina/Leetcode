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
  int maxProfit(vector<int>& prices) {
    int res = 0;
    for (int i = 0; i < prices.size(); i ++) {
      int maxv = 0;
      for (int j = i + 1; j < prices.size(); j ++) {
        maxv = max(prices[j] - prices[i], maxv);
      }
      res = max(res, maxv);
    }
    return res;   
  }
};