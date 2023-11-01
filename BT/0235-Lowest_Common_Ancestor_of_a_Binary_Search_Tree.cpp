/*
題目：
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

解說：
先比較 p q 與 root 大小，如果皆  < root->val 代表 anc 在左邊，如果一個大一個小代表 root 為 anc

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        if(p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        return root;
    }
};