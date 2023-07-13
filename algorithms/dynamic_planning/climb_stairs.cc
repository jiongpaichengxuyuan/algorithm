#include <iostream>
#include <vector>

// 题目描述：爬楼梯进阶版，一次可以爬1,2,3,...,m层，问有多少种方法可以爬n层的楼梯，完全背包问题
long long ClimbStairs(int m, int n) {
  std::vector<long long> dp(n + 1, 0);
  dp[0] = 1;
  dp[1] = 1;
  for (int i = 2; i <= n; ++i) {
    for (int j = i - m; j < i; ++j) {
      dp[i] += dp[j];
    }
  }
  return dp[n];
}

// 爬楼梯的最小花费
int _764MinCostClimbingStairs(std::vector<int>& cost) {
  std::vector<int> dp(cost.size() + 1, 0);
  dp[0] = 0;
  dp[1] = 0;
  for (int i = 2; i <= cost.size(); ++i) {
    dp[i] = (dp[i - 2] + cost[i - 2]) < (dp[i - 1] + cost[i - 1])
                ? (dp[i - 2] + cost[i - 2])
                : (dp[i - 1] + cost[i - 1]);
  }
  return dp[cost.size()];
}

int main() {
  std::cout << ClimbStairs(2, 10);
  return 0;
}