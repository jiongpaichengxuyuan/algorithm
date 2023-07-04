#include "algotirhm.h"

int main() {
  std::vector<int> vec{2, 1, 4, 3, 5, 7, 6, 9, 8, 0};
  QuickSort(vec, 0, vec.size() - 1);
  PrintVector(vec);
}