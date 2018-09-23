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
    string addBinary(string a, string b) {
        string result;
        int i = 0;
        int bonus = 0;
        while (i < a.size() || i < b.size()) {
            int aa = 0, bb = 0;
            if (i < a.size()) aa = a[i] - '0';
            if (i < b.size()) bb = b[i] - '0';
            int sum = aa + bb + bonus;
            bonus = sum / 2;
            result.insert(result.begin(), sum - bonus * 2 + '0');
            i ++;
            cout << aa << " " << bb << " " << bonus << " " << sum << " ";
            cout << result << endl;
        }
        if (bonus != 0) {
            result.insert(result.begin(), '1');
        }
        return result;
    }
};