/*
題目：
https://leetcode.com/problems/minimum-absolute-difference-in-bst/

解說：
因為是 Binary Search Tree，因此透過 Inorder 方式，將 node value 排序完成。
之後再進行一一比較，計算最小的 diff

有使用到的觀念：
BST, Inorder
*/

#include "../code_function.h"

class Solution {
public:
    void order(TreeNode* root, vector<int>& orderTree)
    {
        if(root->left) order(root->left, orderTree);
        orderTree.push_back(root->val);
        if(root->right) order(root->right, orderTree);
    }

    int getMinimumDifference(TreeNode* root) 
    {
        vector<int> orderTree;
        order(root, orderTree);
        int mindiff = INT_MAX;
        for(int i = 1; i < orderTree.size(); i++){
            mindiff = min(mindiff, orderTree[i]-orderTree[i-1]);
        }
        return mindiff;
    }
};