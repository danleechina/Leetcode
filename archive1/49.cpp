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
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<string, vector<string>> resultHolder;
    for (auto str: strs) {
      string tmp(str);
      sort(tmp.begin(), tmp.end(), myfunction);
      if (resultHolder.find(tmp) == resultHolder.end()) {
        vector<string> r;
        r.push_back(str);
        resultHolder.insert(pair<string, vector<string>>(tmp, r));
      } else {
        resultHolder[tmp].push_back(str);
      }
    }
    vector<vector<string>> result;
    for(auto it = resultHolder.begin(); it != resultHolder.end(); it ++) {
      result.push_back(it->second);
    }
    return result;
  }
};