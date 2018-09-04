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
  vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> result;
    if (words.size() == 0) return result;
    map<string, int> wordToCount;
    for (auto word: words) {
      if (wordToCount.find(word) != wordToCount.end()) {
        wordToCount[word] ++;
      } else {
        wordToCount[word] = 1;
      }
    }
    // cout << wordToCount.size() << endl;
    int checkStep = words[0].length();
    if (checkStep == 0) return result;
    if (checkStep * words.size() > s.length()) return result;

    for (int startIndex = 0; startIndex < s.length(); startIndex ++) {
      map<string, int> copyOfWordToCount(wordToCount);
      int seriesCount = 0;
      while (seriesCount != words.size()) {
        auto rightSubstr = s.substr(startIndex + seriesCount * checkStep, checkStep);
        auto it = copyOfWordToCount.find(rightSubstr);
        if (it != copyOfWordToCount.end() && (*it).second > 0) {
          (*it).second -= 1;
        } else {
          break;
        }
        seriesCount ++;
      }
      if (seriesCount == words.size()) {
        result.push_back(startIndex);
      }
    }
    return result;
  }
};

int main(int argc, char const *argv[])
{
  auto sln = Solution();

  vector<string> p2;
  p2.push_back("foo");
  p2.push_back("bar");
  auto result = sln.findSubstring("barfoothefoobarman", p2);
  cout << endl;
  for (auto ele: result) {
    cout << ele << " ";
  }

  vector<string> pp2;
  pp2.push_back("word");
  pp2.push_back("student");
  result = sln.findSubstring("wordgoodstudentgoodword", pp2);
  cout << endl;
  for (auto ele: result) {
    cout << ele << " ";
  }
  return 0;
}
