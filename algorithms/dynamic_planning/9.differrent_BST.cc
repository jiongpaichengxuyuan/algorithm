#include <iostream>
#include <vector>

using namespace std;

// 思路：每一个数字都可以成为头节点，那么由于BST的特点，左子树的数量和右子树的数量就确定了，而节点数量就可以决定一颗BST的结构有多少种（只要节点的数值都不一样）
int _96NumTrees(int n) {
  vector<int> dp(n + 1, 0);
  dp[0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      dp[i] += dp[j - 1] * dp[i - j];
    }
  }
  return dp[n];
}

int main() {
  std::cout << _96NumTrees(5);
  return 0;
}