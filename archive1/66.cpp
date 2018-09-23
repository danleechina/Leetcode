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
    vector<int> plusOne(vector<int>& digits) {
        int bonus = 1;
        vector<int> result;
        for (int i = digits.size() - 1; i >= 0; i --) {
            int sum = digits[i] + bonus;
            bonus = sum / 10;
            result.insert(result.begin(), sum - bonus * 10);
        }
        if (bonus != 0) {
            result.insert(result.begin(), bonus);
        }
        return result;
    }
};