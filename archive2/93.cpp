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

  vector<string> restoreIpAddresses(string s, vector<int> dotIndexs) {
    vector<string> result;
    int lastDotIndex = dotIndexs.back();
    if (lastDotIndex > (int(s.size())) - 1) return result;
    if (dotIndexs.size() == 4) {
      string s1 = s.substr(dotIndexs[0], dotIndexs[1] - dotIndexs[0]);
      string s2 = s.substr(dotIndexs[1], dotIndexs[2] - dotIndexs[1]);
      string s3 = s.substr(dotIndexs[2], dotIndexs[3] - dotIndexs[2]);
      string s4 = s.substr(dotIndexs[3], s.size() - dotIndexs[3]);
      if (s4.size() > 3 || s3.size() > 3 || s2.size() > 3 || s1.size() > 3) return result;
      int v1 = stoi(s1);
      int v2 = stoi(s2);
      int v3 = stoi(s3);
      int v4 = stoi(s4);
      // cout << s1 << "#" << s2 << "#" << s3 << "#" << s4 << endl;
      if (s1[0] - '0' == 0 && s1.size() != 1) return result;
      if (s2[0] - '0' == 0 && s2.size() != 1) return result;
      if (s3[0] - '0' == 0 && s3.size() != 1) return result;
      if (s4[0] - '0' == 0 && s4.size() != 1) return result;
      if ((v1 >= 0 && v1 <= 255) && (v2 >= 0 && v2 <= 255) 
      && (v3 >= 0 && v3 <= 255) && (v4 >= 0 && v4 <= 255)) {
        result.push_back(s1 + "." + s2 + "." + s3 + "." + s4);
      }
      return result;
    }
    for (int i = 1; i <= 3; i ++) {
      auto tmp  = dotIndexs;
      tmp.push_back(lastDotIndex + i);
      auto smallerResult = restoreIpAddresses(s, tmp);
      result.insert(result.end(), smallerResult.begin(), smallerResult.end());
    }
    return result;
  }
  vector<string> restoreIpAddresses(string s) {
    vector<int> dotIndex;
    dotIndex.push_back(0);
    return restoreIpAddresses(s, dotIndex);
  }
};

int main(int argc, char const *argv[])
{
  Solution s;
  auto r = s.restoreIpAddresses("010010");
  for (auto e: r) {
    cout << e << endl;
  }
  return 0;
}
