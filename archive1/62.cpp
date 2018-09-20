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
    
    int uniquePaths(int m, int n) {
        if (m < n) {
            int tmp = m;
            m = n;
            n = tmp;
        }
        m = m - 1;
        n = n - 1;
        double result = 1;
        double currentMulti = m + 1;
        while (currentMulti <= n + m) {
          result *= currentMulti;
          currentMulti ++;
        }
        double currentDiv = 1;
        while (currentDiv <= n) {
          result /= currentDiv;
          currentDiv ++;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
  Solution sln;
  cout << sln.uniquePaths(111, 12) << endl;
  return 0;
}
