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
  void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visitor, int i, int j)
  {
    if (i >= grid.size() || i < 0)
      return;
    if (j >= grid[0].size() || j < 0)
      return;
    if (grid[i][j] == '0')
      return;
    if (visitor[i][j])
      return;
    visitor[i][j] = true;
    dfs(grid, visitor, i, j - 1);
    dfs(grid, visitor, i, j + 1);
    dfs(grid, visitor, i - 1, j);
    dfs(grid, visitor, i + 1, j);
  }

  int numIslands(vector<vector<char>> &grid)
  {
    int n = grid.size();
    if (n == 0)
      return 0;
    int m = grid[0].size();
    vector<vector<bool>> visitor(n, vector<bool>(m, false));
    int res = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (!visitor[i][j] && grid[i][j] == '1')
        {
          dfs(grid, visitor, i, j);
          res++;
        }
      }
    }
    return res;
  }
};