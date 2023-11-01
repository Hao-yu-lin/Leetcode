/*
題目：
https://leetcode.com/problems/count-complete-tree-nodes/

解說：
探查左右子點個數

有使用到的觀念：
Recursion
*/

#include "../code_function.h"

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};