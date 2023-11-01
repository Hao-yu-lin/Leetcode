/*
題目：
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

解說：


有使用到的觀念：
BT
*/

#include "../code_function.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        /*
        當 root 為零代表他不可能是 anc 返回 nullptr
        當 root 為 p 或 q 代表找到因此返回 該點

        否則就開始 往左往右尋找
        ---
        當返回值，左右都不是 nullptr 代表左右存在 p 與 q，因此他一定是最近的 anc
        否則 哪邊有值就返回哪邊
        */
        if(root == nullptr || root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left != nullptr && right != nullptr) return root;
        else if(left == nullptr && right != nullptr) return right;
        else return left;
    }
};