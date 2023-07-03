#ifndef ALGORITHM_UTILS_DATA_STRUCTURE_H_
#define ALGORITHM_UTILS_DATA_STRUCTURE_H_

#include <iostream>
#include <queue>

#pragma region BinaryTree

struct BinaryTreeNode {
  int val;
  BinaryTreeNode *left;
  BinaryTreeNode *right;
  BinaryTreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 构造二叉树
BinaryTreeNode *ConstructBinaryTree(std::vector<int> &v, uint32_t index) {
  BinaryTreeNode *root = nullptr;
  if (v[index] != -1) root = new BinaryTreeNode(v[index]);
  if (index * 2 + 1 < v.size())
    root->left = ConstructBinaryTree(v, index * 2 + 1);
  if (index * 2 + 2 < v.size())
    root->right = ConstructBinaryTree(v, index * 2 + 2);
  return root;
}

// 前序遍历
void PrintBinaryTreePre(BinaryTreeNode *root) {
  if (root == nullptr) return;
  std::cout << root->val << " ";
  PrintBinaryTreePre(root->left);
  PrintBinaryTreePre(root->right);
}

// 中序遍历
void PrintBinaryTreeIn(BinaryTreeNode *root) {
  if (root == nullptr) return;
  PrintBinaryTreePre(root->left);
  std::cout << root->val << " ";
  PrintBinaryTreePre(root->right);
}

// 后序遍历
void PrintBinaryTreePost(BinaryTreeNode *root) {
  if (root == nullptr) return;
  PrintBinaryTreePre(root->left);
  PrintBinaryTreePre(root->right);
  std::cout << root->val << " ";
}

// 层序遍历 or 广度优先遍历
void PrintBinaryTreeLevel(BinaryTreeNode *root) {
  std::queue<BinaryTreeNode *> node_queue;
  node_queue.push(root);
  int to_be_printed = 1;
  int netx_level = 0;
  while (!node_queue.empty()) {
    to_be_printed--;
    auto node = node_queue.front();
    node_queue.pop();
    std::cout << node->val << " ";
    if (node->left) {
      node_queue.push(node->left);
      ++netx_level;
    }
    if (node->right) {
      node_queue.push(node->right);
      ++netx_level;
    }
    if (to_be_printed == 0) {
      to_be_printed = netx_level;
      netx_level = 0;
      std::cout << "\n";
    }
  }
}

#pragma endregion

#endif