/*
題目：
https://leetcode.com/problems/invert-binary-tree/

解說：


有使用到的觀念：
Recursion
*/

#include "../code_function.h"

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        if(root == nullptr) return nullptr;
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);

        root->left = right;
        root->right = left;
        return root;
    }
};