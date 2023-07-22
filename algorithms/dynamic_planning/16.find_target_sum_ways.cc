#include <iostream>
#include <vector>

using namespace std;

int _494FindTargetSumWays(vector<int>& nums, int target) {
  long long sum = 0;
  for (auto i : nums) sum += i;
  if (abs(target) > sum) return 0;
  if ((sum + target) % 2 == 1) return 0;
  long long bagsize = (sum + target) / 2;
  vector<int> dp(bagsize + 1, 0);
  dp[0] = 1;
  for (int i = 0; i < nums.size(); ++i) {
    for (int j = bagsize; j >= nums[i]; j--) {
      dp[j] += dp[j - nums[i]];
    }
  }

  return dp[bagsize];
}