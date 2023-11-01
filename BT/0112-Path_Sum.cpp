/*
題目：
https://leetcode.com/problems/path-sum/

解說：
使用 recursion 方式往左往右，逐個探查和

有使用到的觀念：
Recursion
*/

#include "../code_function.h"

class Solution {
public:

    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if(root == nullptr) return false;

        if(root->val == targetSum && root->left == nullptr && root->right == nullptr) return true;
    
        targetSum -= root->val;
        
        bool left = hasPathSum(root->left, targetSum);
        bool right = hasPathSum(root->right, targetSum);

        return left || right;
    }

};