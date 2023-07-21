#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool _416CanPartition(vector<int>& nums) {
  long long sum = 0;
  for (auto i : nums) {
    sum += i;
  }
  if (sum % 2 == 1) return false;
  long long target = sum / 2;

  vector<int> dp(target + 1, 0);
  sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size(); ++i) {
    for (int j = target; j >= nums[i]; j--) {
      dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
    }
  }
  if (dp[target] == target) return true;
  return false;
}

int _1049LastStoneWeightII(vector<int>& stones) {
  long long sum = 0;
  for (auto i : stones) {
    sum += i;
  }

  long long target = sum / 2;
  vector<int> dp(target + 1, 0);
  sort(stones.begin(), stones.end());
  for (int i = 0; i < stones.size(); ++i) {
    for (int j = target; j >= stones[i]; j--) {
      dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
    }
  }

  return sum - 2 * dp[target];
}

int main() {
  vector<int> nums{23, 13, 11, 7, 6, 5, 5};
  vector<int> nums2{1, 5, 11, 5};
  if (_416CanPartition(nums))
    cout << "yes" << endl;
  else {
    cout << "no" << endl;
  }
  if (_416CanPartition(nums2))
    cout << "yes" << endl;
  else {
    cout << "no" << endl;
  }
}