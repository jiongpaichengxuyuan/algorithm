#include <iostream>
#include <vector>

using namespace std;

void backtracking(vector<vector<int>>& result, vector<int>& track,
                  vector<int>& candidates, int target, long long& sum,
                  int index) {
  if (sum > target) return;
  if (sum == target) {
    result.push_back(track);
    return;
  }

  for (int i = index; i < candidates.size(); ++i) {
    track.push_back(candidates[i]);
    sum += candidates[i];
    backtracking(result, track, candidates, target, sum, i);
    track.pop_back();
    sum -= candidates[i];
  }
}

vector<vector<int>> _39CombinationSum(vector<int>& candidates, int target) {
  vector<int> track;
  vector<vector<int>> result;
  long long sum = 0;
  backtracking(result, track, candidates, target, sum, 0);
  return result;
}

int main() {
  vector<int> candidates{2, 3, 5};
  int target = 8;
  auto result = _39CombinationSum(candidates, target);
  for (auto v : result) {
    for (auto i : v) {
      cout << i << " ";
    }
    cout << endl;
  }
}