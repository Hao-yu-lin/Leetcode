/*
題目：
https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/

解說：
使用 recursion 方式，回傳 pair<sum, count>

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
    int ans;
public:
    int averageOfSubtree(TreeNode* root) 
    {  
        ans = 0;
        traverse(root);
        return ans;
    }

    // <sum, count>
    pair<long, int> traverse(TreeNode* node)
    {
        if(node == nullptr) return {0, 0};

        auto [left_sum, left_count] = traverse(node->left);
        auto [right_sum, right_count] = traverse(node->right);

        int curr_sum = node->val + left_sum + right_sum;
        int curr_count = 1 + left_count + right_count;

        if(curr_sum/curr_count == node->val) ans++;

        return {curr_sum, curr_count};
    }
};