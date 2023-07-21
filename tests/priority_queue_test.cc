#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct student {
  int score;
  string name;
  int student_number;

  bool operator<(const student& s) const {
    return score > s.score;  // 大顶堆
  }

  student(int s, string n, int sn) : score(s), name(n), student_number(sn) {}
};

void CustomTypeTest() {
  priority_queue<student> priority_q_;
  student s1(89, "wang", 1001001);
  student s2(76, "Li", 1001721);
  student s3(100, "Zhao", 1001321);

  priority_q_.push(s1);
  priority_q_.push(s2);

  cout << priority_q_.top().name << endl;

  priority_q_.push(s3);
  cout << priority_q_.top().name << endl;
  priority_q_.pop();
  cout << priority_q_.top().name << endl;
}

int main() {
  CustomTypeTest();
  return 0;
}