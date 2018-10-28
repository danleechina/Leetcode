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
bool myfunction (int i,int j) { return (i<j); }

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxv = 0;
        if (prices.size() == 0) return maxv;
        int buyValue = prices[0];
        int sellValue = buyValue;
        for (int i = 1; i < prices.size(); i ++) {
            if (prices[i] > sellValue) {
                sellValue = prices[i];
            } else {
                maxv += (sellValue - buyValue);
                buyValue = prices[i];
                sellValue = buyValue;
            }
        }
        maxv += (sellValue - buyValue);
        return maxv;
    }
};