#include <iostream>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

struct Node {
  int key_;
  int value_;
  Node(int key, int value) : key_(key), value_(value) {}
  bool operator<(const Node& r) const { return value_ < r.value_; }
};

void TestDescendingOrderByKeyOfMap() {
  auto compare = [](int a, int b) { return a > b; };
  map<int, int, decltype(compare)> map_(compare);
  map_.insert(make_pair(1, 1));
  map_.insert(make_pair(2, 1));
  map_.insert(make_pair(3, 1));

  for (auto i : map_) {
    cout << i.first << ":" << i.second << endl;
  }
}

void TestOrderByValueOfSet() {
  set<Node> set_;
  map<int, Node> map_;
  unordered_map<int, Node> unordered_map_;
  set_.insert(Node(1, 2));
  set_.insert(Node(2, 3));
  set_.insert(Node(3, 1));
  for (auto i = set_.begin(); i != set_.end(); ++i) {
    cout << i->key_ << ':' << i->value_ << endl;
    unordered_map_.insert(make_pair(i->key_, *i));
  }

  cout << endl;
  auto it = unordered_map_.find(1);
  set_.erase(it->second);

  for (auto i = set_.begin(); i != set_.end(); ++i) {
    cout << i->key_ << ':' << i->value_ << endl;
  }
  cout << endl;
  it = unordered_map_.find(2);
  set_.erase(it->second);
  Node temp = Node(it->second.key_, 5);
  it->second = temp;
  set_.insert(temp);

  for (auto i = set_.begin(); i != set_.end(); ++i) {
    cout << i->key_ << ':' << i->value_ << endl;
  }
}

int main() {
  //   TestDescendingOrderByKeyOfMap();
  TestOrderByValueOfSet();
  return 0;
}