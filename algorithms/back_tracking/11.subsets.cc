#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

void BackTracking(vector<vector<int>>& result, vector<int>& track,
                  vector<int>& nums, int index) {
  if (index > nums.size()) return;
  result.push_back(track);
  for (int i = index; i < nums.size(); ++i) {
    track.push_back(nums[i]);
    BackTracking(result, track, nums, i + 1);
    track.pop_back();
  }
}

vector<vector<int>> _78Subsets(vector<int>& nums) {
  vector<vector<int>> result;
  vector<int> track;
  BackTracking(result, track, nums, 0);
  return result;
}

int main() {
  vector<int> nums{1, 2, 3};
  auto result = _78Subsets(nums);
  for (auto v : result) {
    for (auto i : v) {
      cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}