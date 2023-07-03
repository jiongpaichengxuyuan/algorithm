#ifndef ALGORITHM_UTILS_DATA_STRUCTURE_H_
#define ALGORITHM_UTILS_DATA_STRUCTURE_H_

struct BinaryTreeNode {
    int val;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#endif