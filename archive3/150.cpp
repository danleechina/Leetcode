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
    int evalRPN(vector<string> &tokens)
    {
        stack<int> sta;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i].compare("+") == 0)
            {
                auto n2 = sta.top();
                sta.pop();
                auto n1 = sta.top();
                sta.pop();
                sta.push(n1 + n2);
            }
            else if (tokens[i].compare("-") == 0)
            {
                auto n2 = sta.top();
                sta.pop();
                auto n1 = sta.top();
                sta.pop();
                sta.push(n1 - n2);
            }
            else if (tokens[i].compare("*") == 0)
            {
                auto n2 = sta.top();
                sta.pop();
                auto n1 = sta.top();
                sta.pop();
                sta.push(n1 * n2);
            }
            else if (tokens[i].compare("/") == 0)
            {
                auto n2 = sta.top();
                sta.pop();
                auto n1 = sta.top();
                sta.pop();
                sta.push(n1 / n2);
            }
            else
            {
                sta.push(stoi(tokens[i]));
            }
        }
        return sta.top();
    }
};