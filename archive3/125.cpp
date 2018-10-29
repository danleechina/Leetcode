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
  bool isPalindrome(string s)
  {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    int i = 0, j = s.size() - 1;
    while (i < j)
    {
      if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
      {
        if ((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= '0' && s[j] <= '9'))
        {
          if (s[i] != s[j])
            return false;
          else
          {
            i++;
            j--;
          }
        }
        else
        {
          j--;
        }
      }
      else
      {
        i++;
      }
    }
    return true;
  }
};