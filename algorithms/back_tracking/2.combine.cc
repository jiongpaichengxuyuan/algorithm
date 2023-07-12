#include <vector>

#include "data_structure.h"

void CombineByBackTracking(std::vector<std::vector<int>>& result,
                           std::vector<int>& track, int n, int k, int index) {
  if (track.size() == k) {
    result.push_back(track);
    return;
  }
  for (int i = index; i <= n; ++i) {
    track.push_back(i);
    CombineByBackTracking(result, track, n, k, i + 1);
    track.pop_back();
  }
}

// leetcode77 组合
std::vector<std::vector<int>> _77Combie(int n, int k) {
  std::vector<std::vector<int>> result;
  std::vector<int> track;
  CombineByBackTracking(result, track, n, k, 1);
  return result;
}

void CombineByBackTracking3(std::vector<std::vector<int>>& result,
                            std::vector<int>& track, int k, int index, int& cur,
                            int target) {
  if (cur == target && track.size() == k) {
    result.push_back(track);
    return;
  }

  for (int i = index; i <= 9; ++i) {
    if (track.size() > k) break;
    cur += i;
    track.push_back(i);
    CombineByBackTracking3(result, track, k, i + 1, cur, target);
    track.pop_back();
    cur -= i;
  }
}

// 216 组合3
std::vector<std::vector<int>> _216Combine3(int k, int n) {
  std::vector<std::vector<int>> result;
  std::vector<int> track;
  int cur = 0;
  CombineByBackTracking3(result, track, k, 1, cur, n);
  return result;
}

int main() {
  auto result = _77Combie(4, 2);
  for (auto v : result) {
    for (auto i : v) {
      std::cout << i << ",";
    }
    std::cout << std::endl;
  }

  result = _216Combine3(3, 7);
  for (auto v : result) {
    for (auto i : v) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
