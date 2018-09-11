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
  string sum(string num1, string num2) {
    int index = 0;
    int carry = 0;
    string result;
    while(index < num1.size() || index < num2.size()) {
      int n1 = 0;
      if (index < num1.size()) n1 = num1[num1.size() - 1 - index] - '0';
      int n2 = 0;
      if (index < num2.size()) n2 = num2[num2.size() - 1 - index] - '0';
      int mul = n1 + n2 + carry;
      carry = mul / 10;
      int unit = mul - carry * 10;
      index ++;
      result.insert(0, string(1, unit + '0'));
    }
    if (carry != 0) result.insert(0, string(1, carry + '0'));
    return result;
  }

  string multiply(string num1, string num2) {
    if (num1.compare("0") == 0) return "0";
    if (num2.compare("0") == 0) return "0";
    if (num1.size() < num2.size()) {
      string t = num1;
      num1 = num2;
      num2 = t;
    }
    string result;
    for (int i = 0; i < num2.size(); i ++) {
      string mResult;
      for (int j = 0; j < i; j ++) mResult.push_back('0');
      int carry = 0;
      for (int j = 0; j < num1.size(); j ++) {
        int n1 = num2[num2.size() - 1 - i] - '0';
        int n2 = num1[num1.size() - 1 - j] - '0';
        int m = n1 * n2 + carry;
        carry = m / 10;
        mResult.insert(0, string(1, '0' + m - carry * 10));
      }
      if (carry != 0) mResult.insert(0, string(1, carry + '0'));
      result = sum(result, mResult);
    }
    return result;
  }
};

int main(int argc, char const *argv[])
{
  Solution sln;
  cout << sln.multiply("233334", "1") << endl;
  cout << sln.multiply("233334", "112343") << endl;
  cout << sln.multiply("233334", "999999999") << endl;
  return 0;
}
