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
    bool dfs(int row, int col, vector<vector<bool>>& visited, vector<vector<char>>& board, string word, int checkPos) {
        if (checkPos >= word.size()) return true;
        if (row < 0 || row >= board.size()) return false;
        if (col < 0 || col >= board[0].size()) return false;
        if (visited[row][col]) return false;
        if (word[checkPos] != board[row][col]) return false; 
        visited[row][col] = true;
        if (dfs(row + 1, col, visited, board, word, checkPos + 1)) return true;
        if (dfs(row - 1, col, visited, board, word, checkPos + 1)) return true;
        if (dfs(row, col + 1, visited, board, word, checkPos + 1)) return true;
        if (dfs(row, col - 1, visited, board, word, checkPos + 1)) return true;
        visited[row][col] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0) return false;
        vector<vector<bool>> visited;
        for (int i = 0; i < board.size(); i ++) {
            vector<bool> s(board[0].size(), false);
            visited.push_back(s);
        }
        for (int i = 0; i < board.size(); i ++) {
            for (int j = 0; j < board[i].size(); j ++) {
                if (dfs(i, j, visited, board, word, 0)) return true;
            }
        }
        return false;
    }
};