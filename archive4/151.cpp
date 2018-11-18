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
    void reverseWords(string &s)
    {
        vector<string> words;
        int start = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ' || i == s.size() - 1)
            {
                if (i == s.size() - 1 && s[i] != ' ')
                    i++;
                if (i > start)
                {
                    words.push_back(s.substr(start, i - start));
                }
                start = i + 1;
            }
        }
        for (auto w : words)
        {
            cout << '@' << w << '@';
        }
        cout << endl;
        string ns = "";
        for (int i = words.size() - 1; i >= 0; i--)
        {
            ns += words[i];
            if (i != 0)
                ns += " ";
        }
        s = ns;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string str = "";
    s.reverseWords(str);
    cout << '@' << str << '@' << endl;
    return 0;
}
