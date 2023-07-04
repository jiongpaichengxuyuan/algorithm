#include <iostream>
#include <vector>

void PrintVector(std::vector<int>& vec) {
  for (auto i : vec) {
    std::cout << i;
  }
  std::cout << std::endl;
}

int Partition(std::vector<int>& vec, int l, int r) {
  int flag = vec[l];
  int i = l;
  int j = r;
  while (i < j) {
    while (i < j && vec[j] >= flag) j--;
    while (i < j && vec[i] <= flag) i++;
    std::swap(vec[i], vec[j]);
  }
  std::swap(vec[l], vec[i]);
  return i;
}

void QuickSort(std::vector<int>& vec, int l, int r) {
  if (l >= r) return;
  int index = Partition(vec, l, r);
  QuickSort(vec, l, index - 1);
  QuickSort(vec, index + 1, r);
}