class Solution
{
public:
  int titleToNumber(string s)
  {
    if (s.size() == 0)
      return 0;
    int res = s[s.size() - 1] - 'A' + 1;
    int mul = 1;
    for (int i = s.size() - 2; i >= 0; i--)
    {
      mul *= 26;
      res += mul * (s[i] - 'A' + 1);
    }
    return res;
  }
};