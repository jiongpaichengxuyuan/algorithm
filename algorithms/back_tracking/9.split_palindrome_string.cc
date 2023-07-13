#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsPalindrome(const string& s, int start, int end) {
  int i = start;
  int j = end;
  while (i < j) {
    if (s[i] == s[j]) {
      ++i;
      --j;
    } else {
      return false;
    }
  }
  return true;
}

void BackTracking(vector<vector<string>>& result, vector<string>& track,
                  const string& s, int index) {
  if (index >= s.size()) {
    result.push_back(track);
    return;
  }

  for (int i = index; i < s.size(); ++i) {
    if (IsPalindrome(s, index, i)) {
      string str = s.substr(index, i - index + 1);
      track.push_back(str);
    } else {
      continue;
    }
    BackTracking(result, track, s, i + 1);
    track.pop_back();
  }
}

vector<vector<string>> _131Partition(string s) {
  vector<vector<string>> result;
  vector<string> track;
  BackTracking(result, track, s, 0);
  return result;
}

int main() {
  string s = "aab";
  auto result = _131Partition(s);
  for (auto v : result) {
    for (auto i : v) {
      cout << i << " ";
    }
    cout << endl;
  }
}