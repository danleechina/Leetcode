#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
bool myfunction(int i, int j) { return (i < j); }

class Solution
{
public:
  void solve(vector<vector<char>> &board)
  {
    if (board.size() < 3)
      return;
    int rowCnt = board.size();
    int colCnt = board[0].size();
    for (int i = 1; i < rowCnt - 1; i++)
    {
      for (int j = 1; j < colCnt - 1; j++)
      {
        if (board[i][j] == 'O')
          board[i][j] = '#';
      }
    }
    vector<vector<bool>> visited(rowCnt, vector<bool>(colCnt, false));
    // cout << visited.size() << ' ' << visited[0].size() << endl;
    for (int i = 0; i < rowCnt; i++)
    {
      dfs(board, visited, i, 0);
      dfs(board, visited, i, colCnt - 1);
    }
    for (int i = 0; i < colCnt; i++)
    {
      dfs(board, visited, 0, i);
      dfs(board, visited, rowCnt - 1, i);
    }
    for (int i = 1; i < rowCnt - 1; i++)
    {
      for (int j = 1; j < colCnt - 1; j++)
      {
        if (board[i][j] == '#')
          board[i][j] = 'X';
      }
    }
  }

  void dfs(vector<vector<char>> &board, vector<vector<bool>> &visited, int startX, int startY)
  {
    if (startX < 0 || startY < 0)
      return;
    if (startX >= board.size())
      return;
    if (startY >= board[0].size())
      return;
    if (visited[startX][startY])
      return;
    if (board[startX][startY] == 'X')
      return;
    visited[startX][startY] = true;
    if (board[startX][startY] == '#')
      board[startX][startY] = 'O';
    dfs(board, visited, startX - 1, startY);
    dfs(board, visited, startX + 1, startY);
    dfs(board, visited, startX, startY + 1);
    dfs(board, visited, startX, startY - 1);
  }
};

int main(int argc, char const *argv[])
{
  Solution s;
  vector<char> r1 = {'X', 'X', 'X', 'X'};
  vector<char> r2 = {'X', 'O', 'O', 'X'};
  vector<char> r3 = {'X', 'X', 'O', 'X'};
  vector<char> r4 = {'X', 'O', 'X', 'X'};
  vector<vector<char>> r = {r1, r2, r3, r4};
  s.solve(r);
  for (auto e1 : r)
  {
    for (auto e2 : e1)
    {
      cout << e2 << ' ';
    }
    cout << endl;
  }
  return 0;
}
