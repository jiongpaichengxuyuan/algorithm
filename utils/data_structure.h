#ifndef ALGORITHM_UTILS_DATA_STRUCTURE_H_
#define ALGORITHM_UTILS_DATA_STRUCTURE_H_

#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

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
  PrintBinaryTreeIn(root->left);
  std::cout << root->val << " ";
  PrintBinaryTreeIn(root->right);
}

// 后序遍历
void PrintBinaryTreePost(BinaryTreeNode *root) {
  if (root == nullptr) return;
  PrintBinaryTreePost(root->left);
  PrintBinaryTreePost(root->right);
  std::cout << root->val << " ";
}

// 迭代前序遍历
// 思路：每一次都把当前节点弹出，然后将其右、左节点压入
void PrintBinaryTreePreIteratively(BinaryTreeNode *root) {
  if (root == nullptr) return;
  std::stack<BinaryTreeNode *> node_stack;
  node_stack.push(root);
  while (!node_stack.empty()) {
    auto node = node_stack.top();
    node_stack.pop();
    std::cout << node->val << " ";
    if (node->right) node_stack.push(node->right);
    if (node->left) node_stack.push(node->left);
  }
}

// 迭代中序遍历
// 思路：
// 利用cur_node指针遍历二叉树，利用栈处理节点，只要当前cur_node是nullptr，那么就可以进行处理，即当前栈顶的节点需要被处理
void PrintBinaryTreeInIteratively(BinaryTreeNode *root) {
  if (root == nullptr) return;
  std::stack<BinaryTreeNode *> node_stack;
  auto cur_node = root;
  while (cur_node || !node_stack.empty()) {
    if (cur_node) {
      node_stack.push(cur_node);
      cur_node = cur_node->left;
    } else {
      cur_node = node_stack.top();
      node_stack.pop();
      std::cout << cur_node->val << " ";
      cur_node = cur_node->right;
    }
  }
}

// 迭代后序遍历
void PrintBinaryTreePostIteratively(BinaryTreeNode *root) {
  if (root == nullptr) return;
  std::stack<BinaryTreeNode *> node_stack;
  node_stack.push(root);
  std::vector<int> result;
  while (!node_stack.empty()) {
    auto node = node_stack.top();
    node_stack.pop();
    result.push_back(node->val);
    if (node->left) node_stack.push(node->left);
    if (node->right) node_stack.push(node->right);
  }
  reverse(result.begin(), result.end());
  for (auto i : result) std::cout << i << " ";
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