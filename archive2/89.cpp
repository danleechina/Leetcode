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
  vector<int> grayCode(int n) {
    vector<int> result;
    result.push_back(0);
    if (n == 0) return result;
    set<int> alreadyChecked;
    alreadyChecked.insert(0);
    int currentNum = 0;
    while(true) {
      bool allOk = false;
      int now, x;
      for (int i = 0; i < n; i ++) {
        x = 1 << i;
        if((currentNum & x) == 0) {
          now = currentNum | x;
        } else {
          now = currentNum ^ x;
        }
        if (alreadyChecked.find(now) == alreadyChecked.end()) {
          result.push_back(now);
          alreadyChecked.insert(now);
          currentNum = now;
          allOk = true;
          break;
        }
      }
      if (!allOk) break;
    }
    return result;
  }
};