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

void BackTracking2(vector<vector<int>>& result, vector<int>& track,
                   vector<int>& nums, int index) {
  if (index > nums.size()) return;
  result.push_back(track);
  for (int i = index; i < nums.size(); ++i) {
    if (i > index && nums[i] == nums[i - 1]) continue;
    track.push_back(nums[i]);
    BackTracking2(result, track, nums, i + 1);
    track.pop_back();
  }
}

void BackTracking3(vector<vector<int>>& result, vector<int>& track,
                   vector<int>& nums, int index) {
  if (index > nums.size()) return;
  if (track.size() >= 2) result.push_back(track);
  bool is_exist = false;
  for (int i = index; i < nums.size(); ++i) {
    if (i > index) {
      for (int j = index; j < i; ++j) {
        if (nums[j] == nums[i]) {
          is_exist = true;
          break;
        }
      }
    }
    if (is_exist) {
      is_exist = false;
      continue;
    }
    if (track.size() != 0 && nums[i] < track.back()) continue;
    track.push_back(nums[i]);
    BackTracking3(result, track, nums, i + 1);
    track.pop_back();
  }
}

vector<vector<int>> _78Subsets(vector<int>& nums) {
  vector<vector<int>> result;
  vector<int> track;
  BackTracking(result, track, nums, 0);
  return result;
}

vector<vector<int>> _90Subsets2(vector<int>& nums) {
  vector<vector<int>> result;
  vector<int> track;
  sort(nums.begin(), nums.end());
  BackTracking2(result, track, nums, 0);
  return result;
}

vector<vector<int>> _491FindSubsequences(vector<int>& nums) {
  vector<vector<int>> result;
  vector<int> track;
  BackTracking3(result, track, nums, 0);
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