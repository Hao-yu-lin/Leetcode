/*
題目：
https://leetcode.com/problems/kth-smallest-element-in-a-bst/

解說：
因為是 Binary Search Tree，因此透過 Inorder 方式，將 node value 排序完成。
之後找出第 k 個值即可。

有使用到的觀念：
BST, Inorder
*/

#include "../code_function.h"

class Solution {
public:
    void order(TreeNode* root, vector<int>& orderTree)
    {
        if(root->left) order(root->left, orderTree);
        orderTree.push_back(root->val);
        if(root->right) order(root->right, orderTree);
    }

    int kthSmallest(TreeNode* root, int k) 
    {
        vector<int> orderTree;
        order(root, orderTree);
        return orderTree[k-1];
    }
};