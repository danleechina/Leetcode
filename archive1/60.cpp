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
  string getPermutation(int n, int k) {
    string result;
    for (int i = 0; i < n; i ++) result.push_back('1' + i);
    int order = 1;
    while (order < k) {
      next_permutation(result.begin(), result.end());
      order ++;
    }
    return result;
  }
};