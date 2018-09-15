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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size();
        if (m == 0) return result;
        int n = matrix[0].size();
        for (int i = 0; i < (m + 1)/2 && i < (n + 1)/2; i ++) {
            for (int step = 0; step < 4; step ++) {
                if (step == 0) {
                    for (int j = i; j < n - i - 1; j ++) {
                        result.push_back(matrix[i][j]);
                    }
                 } else if (step == 1) {
                     for (int j = i; j < m - i - 1; j ++) {
                         result.push_back(matrix[j][n - i - 1]);
                     }
                 } else if (step == 2) {
                     for (int j = n - i - 1; j > i; j --) {
                         result.push_back(matrix[m - i - 1][j]);
                     }
                 } else {
                     for (int j = m - i - 1; j > i; j --) {
                         result.push_back(matrix[j][i]);
                     }
                     if (m == n && i + 1 == (m + 1)/2) result.push_back(matrix[i][i]);
                 }
                 cout << step << ":" << endl;
                 for (auto r: result) {
                     cout << r << " ";
                 }
                 cout << endl;
            }
        }
        if (result.size() > m * n) {
            result.erase(result.end() - result.size() + m * n, result.end());
        }
        return result;
    }
};


/*

1 1 1 1 1 1 1
2 2 2 2 2 2 2 
3 3 3 3 3 3 3
4 4 4 4 4 4 4 
5 5 5 5 5 5 5 

1 1 1
2 2 2

1 1 1
2 2 2 
3 3 3

1 1 1
2 2 2
3 3 3
4 4 4
*/