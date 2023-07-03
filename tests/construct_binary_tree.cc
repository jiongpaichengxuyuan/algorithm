#include <iostream>
#include <queue>
#include <vector>

#include "data_structure.h"

using namespace std;

int main() {
  vector<int> vec = {4, 1, 6, 0, 2, 5, 7, -1, -1, -1, 3, -1, -1, -1, 8};
  BinaryTreeNode* root = ConstructBinaryTree(vec, 0);
  PrintBinaryTreePre(root);
  std::cout << std::endl;
  PrintBinaryTreePreIteratively(root);
  std::cout << std::endl;
  PrintBinaryTreeIn(root);
  std::cout << std::endl;
  PrintBinaryTreeInIteratively(root);
  std::cout << std::endl;
  PrintBinaryTreePost(root);
  std::cout << std::endl;
  PrintBinaryTreePostIteratively(root);
  std::cout << std::endl;
}