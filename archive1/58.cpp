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
  int lengthOfLastWord(string s) {
    int result = 0;
    int i = s.size() - 1;
    bool hasEncounterWord = false;
    while (i >= 0) {
      if (hasEncounterWord) {
        if (s[i] == ' ') break;
        else result ++;
      } else {
        if (s[i] != ' ') {
          hasEncounterWord = true;
          result ++;
        }
      }
      i --;
    }
    return result;
  }
};