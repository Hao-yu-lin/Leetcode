/*
題目：
https://leetcode.com/problems/binary-tree-postorder-traversal/description/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
    vector<int> ans;
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        if(root == nullptr) return {};
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        ans.push_back(root->val);

        return ans;
    }
};