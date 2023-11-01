/*
題目：
https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

解說：
檢查有無左子樹，有的話將右子樹，移動到左子樹他的右子樹。

有使用到的觀念：
Linked List, Binary Tree
*/

#include "../code_function.h"

class Solution {
public:
    void flatten(TreeNode* root) 
    {
        if(root == nullptr) return;
        TreeNode* curr = root;
        while(curr)
        {
            if(curr->left)
            {
                TreeNode* pre = curr->left;
                while(pre->right) pre = pre->right;
                pre->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }    
    }
};