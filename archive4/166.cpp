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
bool myfunction(int i, int j) { return (i < j); }

class Solution
{
public:
  string fractionToDecimal(int numerator, int denominator)
  {
    if (numerator == 0)
      return "0";
    string res;
    if (numerator < 0 ^ denominator < 0)
      res += '-';
    long numer = abs((long)numerator);
    long denom = abs((long)denominator);
    long interg = numer / denom;
    res += to_string(interg);
    long rmd = numer % denom;
    if (rmd == 0)
      return res;
    res += '.';
    rmd *= 10;
    map<int, int> mp;
    while (rmd != 0)
    {
      if (mp.find(rmd) != mp.end())
      {
        res.insert(mp[rmd], 1, '(');
        res += ')';
        break;
      }
      mp[rmd] = res.size();
      long interg = rmd / denom;
      res += to_string(interg);
      rmd = (rmd % denom) * 10;
    }
    return res;
  }
};