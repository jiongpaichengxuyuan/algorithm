#include <iostream>
#include <vector>

using namespace std;

int _12_01Backpack(vector<int>& weight, vector<int>& value, int bag_weight) {
  vector<int> dp(bag_weight + 1, 0);
  for (int i = 0; i < weight.size(); ++i) {
    for (int j = bag_weight; j >= weight[i]; j--) {
      dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    }
  }
  return dp[bag_weight];
}

int main() {
  vector<int> weight = {1, 3, 4};
  vector<int> value = {15, 20, 30};
  std::cout << _12_01Backpack(weight, value, 4);
}