#include <iostream>
#include <vector>

using namespace std;

int _63UniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
  int m = obstacleGrid.size();
  int n = obstacleGrid[0].size();
  vector<int> dp(m * n, 0);
  dp[0] = 1;
  for (int row = 0; row < m; ++row) {
    for (int col = 0; col < n; ++col) {
      if (obstacleGrid[row][col] == 1) continue;
      if (row - 1 >= 0 && obstacleGrid[row - 1][col] == 0) {
        dp[row * n + col] += dp[(row - 1) * n + col];
      }
      if (col - 1 >= 0 && obstacleGrid[row][col - 1] == 0) {
        dp[row * n + col] += dp[row * n + col - 1];
      }
      if (dp[row * n + col] == 0) obstacleGrid[row][col] = 1;
    }
  }
  if (obstacleGrid[0][0] == 1) dp[0] = 0;
  return dp[m * n - 1];
}

int main() {
  vector<vector<int>> o = {{1, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  std::cout << _63UniquePathsWithObstacles(o);
}