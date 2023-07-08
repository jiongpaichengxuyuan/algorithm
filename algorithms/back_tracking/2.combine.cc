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

int main(){
  auto result = _77Combie(4, 2);
  for(auto v : result){
    for(auto i : v){
      std::cout<< i << ",";
    }
    std::cout<< std::endl;
  }
}
