#include "data_structure.h"

void ReveseBinaryTree(BinaryTreeNode* root){
  if(root == nullptr) return;
  BinaryTreeNode* temp = root->left;
  root->left = root->right;
  root->right = temp;
  ReveseBinaryTree(root->right);
  ReveseBinaryTree(root->left);
}

int main(){
  std::vector<int> vec = {4, 1, 6, 0, 2, 5, 7, -1, -1, -1, 3, -1, -1, -1, 8};
  BinaryTreeNode* root = ConstructBinaryTree(vec, 0);
  PrintBinaryTreeLevel(root);
  ReveseBinaryTree(root);
  PrintBinaryTreeLevel(root);
  return 0;
}
