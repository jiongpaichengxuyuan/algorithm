#include "data_structure.h"

// 自底向上层序打印二叉树
void _107BinaryTreeLevelOrderTraversal2(BinaryTreeNode* root) {
  std::stack<std::vector<int>> result_stack;
  std::queue<BinaryTreeNode*> node_queue;
  int to_be_printed = 1;
  int next_level = 0;
  node_queue.push(root);
  std::vector<int> result_per_level;
  while (!node_queue.empty()) {
    auto node = node_queue.front();
    node_queue.pop();
    result_per_level.push_back(node->val);
    to_be_printed--;
    if (node->left) {
      node_queue.push(node->left);
      next_level++;
    }
    if (node->right) {
      node_queue.push(node->right);
      next_level++;
    }
    if (to_be_printed == 0) {
      to_be_printed = next_level;
      next_level = 0;
      result_stack.emplace(std::move(result_per_level));
    }
  }
  while (!result_stack.empty()) {
    auto v = result_stack.top();
    result_stack.pop();
    for (auto i : v) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }
}

// 二叉树最大深度
int _104BinaryTreeMaxDepth(BinaryTreeNode* root) {
  if (root == nullptr) return 0;
  int left = _104BinaryTreeMaxDepth(root->left);
  int right = _104BinaryTreeMaxDepth(root->right);
  return (left > right ? left : right) + 1;
}

// 二叉树最小深度，这个和最大深度有区别，如果左右子树其中一个为空，另一个不为空则需要基于不为空的子树计算深度
int _111BinaryTreeMinDepth(BinaryTreeNode* root) {
  if (root == nullptr) return 0;
  if (root->left && !root->right) return 1 + _111BinaryTreeMinDepth(root->left);
  if (!root->left && root->right)
    return 1 + _111BinaryTreeMinDepth(root->right);

  int left = _111BinaryTreeMinDepth(root->left);
  int right = _111BinaryTreeMinDepth(root->right);
  return (left < right ? left : right) + 1;
}

int main() {
  std::vector<int> vec = {4, 1, 6, 0, 2, 5, 7, -1, -1, -1, 3, -1, -1, -1, 8};
  BinaryTreeNode* root = ConstructBinaryTree(vec, 0);
  PrintBinaryTreeLevel(root);
  std::cout << std::endl;
  _107BinaryTreeLevelOrderTraversal2(root);
  std::cout << std::endl;
  std::cout << _104BinaryTreeMaxDepth(root);
  std::cout << std::endl;
  std::cout << _111BinaryTreeMinDepth(root);
  std::cout << std::endl;
}