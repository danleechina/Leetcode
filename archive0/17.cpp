#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
  map<string, vector<string>> intToChars;
public:
  Solution() {
    // map<string, vector<string>> intToChars;
    vector<string> chars2;
    chars2.push_back("a");
    chars2.push_back("b");
    chars2.push_back("c");
    intToChars["2"] = chars2;

    vector<string> chars3;
    chars3.push_back("d");
    chars3.push_back("e");
    chars3.push_back("f");
    intToChars["3"] = chars3;

    vector<string> chars4;
    chars4.push_back("g");
    chars4.push_back("h");
    chars4.push_back("i");
    intToChars["4"] = chars4;

    vector<string> chars5;
    chars5.push_back("j");
    chars5.push_back("k");
    chars5.push_back("l");
    intToChars["5"] = chars5;

    vector<string> chars6;
    chars6.push_back("m");
    chars6.push_back("n");
    chars6.push_back("o");
    intToChars["6"] = chars6;

    vector<string> chars7;
    chars7.push_back("p");
    chars7.push_back("q");
    chars7.push_back("r");
    chars7.push_back("s");
    intToChars["7"] = chars7;

    vector<string> chars8;
    chars8.push_back("t");
    chars8.push_back("u");
    chars8.push_back("v");
    intToChars["8"] = chars8;

    vector<string> chars9;
    chars9.push_back("w");
    chars9.push_back("x");
    chars9.push_back("y");
    chars9.push_back("z");
    intToChars["9"] = chars9;
  }
  
  vector<string> letterCombinations(string digits) {
    vector<string> result;
    if (digits.length() == 0) {
      return result;
    }
    if (digits.length() == 1) {
      return this->intToChars[string(1, digits[0])];
    }

    auto toBeAdded = this->intToChars[string(1, digits[0])];
    auto nextToBeAdded = letterCombinations(digits.substr(1, digits.length() - 1));
    for (auto p: toBeAdded) {
      for (auto s: nextToBeAdded) {
        result.push_back(p + s);
      }
    }

    return result;
  }
};

int main(int argc, char const *argv[])
{
  auto sln = Solution();
  auto result = sln.letterCombinations("234");
  for (auto r: result) {
    cout << r << endl;
  }
  // cout << sln.letterCombinations("23333");
  return 0;
}
