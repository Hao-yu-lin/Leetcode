/*
題目：
https://leetcode.com/problems/binary-tree-preorder-traversal/description/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
    vector<int> ans;
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        if(root == nullptr) return {};
        ans.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return ans;
    }
};