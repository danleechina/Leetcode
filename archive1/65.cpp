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
    bool isNumber(string s) {
        if (s.size() == 0) return false;
        int startChar = 0;
        for(int i = 0; i < s.size(); i ++) {
            if (s[i] == ' ') startChar ++;
            else break;
        }
        int endChar = s.size();
        for (int i = s.size() - 1; i >= 0; i --) {
            if (s[i] == ' ') endChar --;
            else break;
        }
        if (endChar - startChar <= 0) return false;
        if (endChar - startChar == 1) {
            return s[startChar] >= '0' && s[startChar] <= '9';
        }
        bool hasEncountPoint = false;
        bool hasEncountE = false;
        bool hasEncountNumber = false;
        if (s[startChar] == 'e' || s[startChar] == 'E') return false;
        if (s[endChar - 1] == 'e' || s[endChar - 1] == 'E') return false;
        for (int i = startChar; i < endChar; i ++) {
            if (s[i] == '.') {
                if (hasEncountPoint) return false;
                hasEncountPoint = true;
            } else if (s[i] == 'E' || s[i] == 'e') {
                if (hasEncountE) return false;
                if (!hasEncountNumber) return false;
                hasEncountE = true;
                hasEncountNumber = false;
            } else if (s[i] < '0' && s[i] > '9') {
                return false;
            } else if (s[i] == ' ') {
                return false;
            } else {
                hasEncountNumber = true;
            }
        }
        return hasEncountNumber;
    }
};