#include <iostream>
#include <vector>

int GetSumByNum(int num) {
  int sum = 0;
  while (num != 0) {
    sum += num % 10;
    num /= 10;
  }
  return sum;
}

bool CheckNext(int row, int col, int limit, int m, int n,
               std::vector<bool>& visited) {
  if (row < 0 || col < 0 || row > m - 1 || col > n - 1) return false;
  if (visited[row * n + col]) return false;
  int sum = GetSumByNum(row) + GetSumByNum(col);
  if (sum <= limit) return true;
  return false;
}

void Count(int row, int col, std::vector<bool>& visited, long long& count,
           int m, int n, int limit) {
  ++count;
  visited[row * n + col] = true;
  if (!CheckNext(row - 1, col, limit, m, n, visited) &&
      !CheckNext(row + 1, col, limit, m, n, visited) &&
      !CheckNext(row, col - 1, limit, m, n, visited) &&
      !CheckNext(row, col + 1, limit, m, n, visited))
    return;
  if (CheckNext(row - 1, col, limit, m, n, visited)) {
    Count(row - 1, col, visited, count, m, n, limit);
  }
  if (CheckNext(row + 1, col, limit, m, n, visited)) {
    Count(row + 1, col, visited, count, m, n, limit);
  }
  if (CheckNext(row, col - 1, limit, m, n, visited)) {
    Count(row, col - 1, visited, count, m, n, limit);
  }
  if (CheckNext(row, col + 1, limit, m, n, visited)) {
    Count(row, col + 1, visited, count, m, n, limit);
  }
}

int MovingCount(int m, int n, int k) {
  std::vector<bool> visited(m * n, false);
  long long count = 0;
  Count(0, 0, visited, count, m, n, k);
  return count;
}

int main() {
  auto result = MovingCount(3, 1, 0);
  std::cout << result;
}