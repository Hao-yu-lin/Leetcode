/*
題目：
https://leetcode.com/problems/longest-univalue-path/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
    int ans;
public:
    int longestUnivaluePath(TreeNode* root) 
    {
        ans = 0;
        findsame(root);
        return ans;
    }

    int findsame(TreeNode* root)
    {
        if(root == nullptr) return 0;
        int left = findsame(root->left);
        int right = findsame(root->right);
        int pl = 0;
        int pr = 0;

        if(root->left && root->left->val == root->val) pl = left+1;
        if(root->right && root->right->val == root->val) pr = right+1;

        ans = max(ans, pl+pr);
        return max(pl, pr);
    }
};