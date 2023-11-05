/*
題目：
https://leetcode.com/problems/find-mode-in-binary-search-tree/

解說：
使用 Inorder , Preorder 與 Postorder 皆不行

有使用到的觀念：
Inorder
*/

#include "../code_function.h"

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        Inorder(root);

        return modes;
    }

    void Inorder(TreeNode* node)
    {
        if(node == nullptr) return;
        
        Inorder(node->left);

        
        curr_count = (node->val == curr_val) ? curr_count+1 : 1;
        if(curr_count == max_count) modes.push_back(node->val);
        else if(curr_count > max_count)
        {
            max_count = curr_count;
            modes = {node->val};
        }
        curr_val = node->val;
        
        Inorder(node->right);
    }

private:
    int curr_count = 0;
    int max_count = 0;
    int curr_val = 0;
    vector<int> modes;
};