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
  int numDecodings(string s, int start, int end) {
    if (start > end) return 0;
    if (s[start] == '#') {
      int result = numDecodings(s, start + 1, end);
      return result == 0 ? 1 : result;
    }
    int startValue = s[start] - '0';
    if (start == end) {
      return startValue == 0 ? 0 : 1;
    }
    int result;
    int nextStartValue = s[start + 1] - '0';
    if (s[start + 1] == '#') {
      int tmp = numDecodings(s, start + 2, end);
      if (tmp == 0) tmp = 1;
      result = tmp;
    } else {
      if (nextStartValue == 0) {
        result = numDecodings(s, start + 2, end);
        if (result == 0) result = 1;
      } else {
        if (startValue > 2) {
          result = numDecodings(s, start + 1, end);
        } else if (startValue == 2) {
          if (nextStartValue > 6) {
            result = numDecodings(s, start + 1, end);
          } else {
            result = numDecodings(s, start + 1, end);
            int tmp = numDecodings(s, start + 2, end);
            if (tmp == 0) tmp = 1;
            result += tmp;
          }
        } else {
          result = numDecodings(s, start + 1, end);
          int tmp = numDecodings(s, start + 2, end);
          if (tmp == 0) tmp = 1;
          result += tmp;
        }
      }
    }
    return result;
  }

  bool isValid(string s) {
    for (int i = 0; i < s.size(); i ++) {
      int value = s[i] - '0';
      if (value == 0) {
        if (i == 0) return false;
        else {
          int preValue = s[i - 1] - '0';
          if (preValue == 0 || preValue > 2) return false;
        }
      }
    }
    return true;
  }

  string getRidOfZero(string s) {
    string result = s;
    for (auto begin = result.begin(); begin != result.end();) {
      int value = (*begin) - '0';
      if (value == 0) {
        *begin = '#';
        result.erase(begin - 1);
      } else {
        begin ++;
      }
    }
    return result;
  }

  int numDecodings(string s) {
    if (!isValid(s)) return 0;
    auto newS = getRidOfZero(s);
    if (newS.size() == 1) return 1;

    int result = 1;
    int preResult = 1;
    char preChar = 0;
    int start = 0;
    for (; start < newS.size(); start ++) {
      if (newS[start] != '#') {
        preChar = newS[start];
        preResult = 1;
        start ++;
        break;
      }
    }
    for (int i = start; i < newS.size(); i ++) {
      if (newS[i] == '#') {
        preResult = 0;
        preChar = 0;
      } else {
        int tmp = result;
        if (preChar - '0' > 2 
        || (preChar - '0' == 2 && newS[i] - '0' > 6) 
        || preChar == 0) {}
        else {
          result += preResult;
        }
        preResult = tmp;
        preChar = newS[i];
      }
    }
    // int r = numDecodings(newS, 0, newS.size() - 1);
    // cout << r << " " << result << endl;
    return result;
  }
};

int main(int argc, char const *argv[])
{
  Solution s;
  s.numDecodings("101");//1
  s.numDecodings("1");//1
  s.numDecodings("110101");//1
  s.numDecodings("226");//3
  s.numDecodings("22610");//3
  s.numDecodings("12");//2
  s.numDecodings("10");//1
  s.numDecodings("27");//1  
  s.numDecodings("1787897759966261825913315262377298132516969578441236833255596967132573482281598412163216914566534565");

  return 0;
}
