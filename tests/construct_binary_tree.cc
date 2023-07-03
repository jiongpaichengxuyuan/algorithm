#include "data_structure.h"
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

// 根据数组构造二叉树
BinaryTreeNode* construct_binary_tree(const vector<int>& vec) {
    vector<BinaryTreeNode*> vecTree (vec.size(), nullptr);
    BinaryTreeNode* root = nullptr;
    for (int i = 0; i < vec.size(); i++) {
        BinaryTreeNode* node = nullptr;
        if (vec[i] != -1) node = new BinaryTreeNode(vec[i]);
        vecTree[i] = node;
        if (i == 0) root = node;
    }
    for (int i = 0; i * 2 + 1 < vec.size(); i++) {
        if (vecTree[i] != nullptr) {
            vecTree[i]->left = vecTree[i * 2 + 1];
            if(i * 2 + 2 < vec.size())
            vecTree[i]->right = vecTree[i * 2 + 2];
        }
    }
    return root;
}

void print_binary_tree(BinaryTreeNode* root) {
    queue<BinaryTreeNode*> que;
    if (root != NULL) que.push(root);
    vector<vector<int>> result;
    while (!que.empty()) {
        int size = que.size();
        vector<int> vec;
        for (int i = 0; i < size; i++) {
            BinaryTreeNode* node = que.front();
            que.pop();
            if (node != NULL) {
                vec.push_back(node->val);
                que.push(node->left);
                que.push(node->right);
            }
            // 这里的处理逻辑是为了把null节点打印出来，用-1 表示null
            else vec.push_back(-1);
        }
        result.push_back(vec);
    }
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    vector<int> vec = {4,1,6,0,2,5,7,-1,-1,-1,3,-1,-1,-1,8};
    BinaryTreeNode* root = construct_binary_tree(vec);
    print_binary_tree(root);
}