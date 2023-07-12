#include <iostream>
#include <string>
#include <vector>

void CombineByBacktracking17(std::vector<std::string>& result,
                             std::string& track, std::string& digits,
                             std::vector<std::string>& letters_map, int index) {
  if (track.size() == digits.size()) {
    result.push_back(track);
    return;
  }
  for (int j = 0; j < letters_map[(int)digits[index] - 48].size(); ++j) {
    track += letters_map[(int)digits[index] - 48][j];
    CombineByBacktracking17(result, track, digits, letters_map, index + 1);
    track.pop_back();
  }
}

std::vector<std::string> _17PhoneNumberMapCombine(std::string digits) {
  std::vector<std::string> result;
  std::vector<std::string> letters_map = {"",    "",    "abc",  "def", "ghi",
                                          "jkl", "mno", "pqrs", "tuv", "wxyz"};
  int n = (int)digits[0];
  std::string track = "";
  CombineByBacktracking17(result, track, digits, letters_map, 0);
  return result;
}

int main() {
  auto result = _17PhoneNumberMapCombine("23");
  for (auto v : result) {
    std::cout << v << " ";
  }
}
