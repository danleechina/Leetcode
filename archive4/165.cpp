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
  int compareVersion(string version1, string version2)
  {
    int start = 0;
    int pointPos = version1.find('.');
    vector<int> versioni1;
    vector<int> versioni2;
    while (pointPos != string::npos)
    {
      versioni1.push_back(stoi(version1.substr(start, pointPos - start)));
      start = pointPos + 1;
      pointPos = version1.find('.', start);
    }
    versioni1.push_back(stoi(version1.substr(start, version1.size() - start)));
    start = 0;
    pointPos = version2.find('.');
    while (pointPos != string::npos)
    {
      versioni2.push_back(stoi(version2.substr(start, pointPos - start)));
      start = pointPos + 1;
      pointPos = version2.find('.', start);
    }
    versioni2.push_back(stoi(version2.substr(start, version2.size() - start)));

    int i = versioni1.back();
    while (i == 0 && !versioni1.empty())
    {
      versioni1.pop_back();
      i = versioni1.back();
    }
    i = versioni2.back();
    while (i == 0 && !versioni2.empty())
    {
      versioni2.pop_back();
      i = versioni2.back();
    }
    for (auto s : versioni1)
    {
      cout << s << ' ';
    }
    cout << endl;
    for (auto s : versioni2)
    {
      cout << s << ' ';
    }
    cout << endl;
    for (int i = 0; i < versioni1.size() || i < versioni2.size(); i++)
    {
      if (i >= versioni1.size())
        return -1;
      if (i >= versioni2.size())
        return 1;
      if (versioni1[i] > versioni2[i])
        return 1;
      else if (versioni1[i] < versioni2[i])
        return -1;
    }
    return 0;
  }
};

int main(int argc, char const *argv[])
{
  Solution s;
  cout << s.compareVersion("1.11", "1.1") << endl;
  return 0;
}
