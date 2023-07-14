#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool CheckIsIPSegment(string& seg) {
  if (seg == "") return false;
  if (seg.size() > 3) return false;
  if (seg[0] == '0' && seg.size() > 1) return false;
  int num = 0;
  int n = seg.size();
  for (int i = 0; i < n; ++i) {
    if (n - 1 - i == 2)
      num += (seg[i] - '0') * 100;
    else if (n - 1 - i == 1)
      num += (seg[i] - '0') * 10;
    else
      num += (seg[i] - '0');
  }
  if (num > 255) return false;
  return true;
}

void BackTracking(vector<string>& result, string& track, string& s, int index,
                  int& count) {
  if (count == 4 && track.size() != s.size() + 4) return;
  if (track.size() == s.size() + 4) {
    string temp = track;
    temp.pop_back();
    result.push_back(temp);
    return;
  }

  for (int i = index; i < s.size(); ++i) {
    string seg = s.substr(index, i - index + 1);
    if (CheckIsIPSegment(seg)) {
      track += seg;
      track += '.';
      count++;
      BackTracking(result, track, s, i + 1, count);
    } else {
      continue;
    }
    for (int j = 0; j < (i - index + 2); ++j) {
      track.pop_back();
    }
    count--;
  }
}

vector<string> _94RecoveryIPAddress(string s) {
  vector<string> result;
  string track;
  int count = 0;
  BackTracking(result, track, s, 0, count);
  return result;
}

int main() {
  string s = "25525511135";
  auto result = _94RecoveryIPAddress(s);
  for (auto v : result) {
    for (auto i : v) {
      cout << i;
    }
    cout << endl;
  }
}