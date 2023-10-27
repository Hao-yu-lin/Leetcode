/*
題目：
https://leetcode.com/problems/symmetric-tree/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    bool check(TreeNode* p1, TreeNode* p2){
        if(p1 == NULL && p2 == NULL) return true;
        if(p1 == NULL || p2 == NULL) return false;
        if(p1->val != p2->val) return false;

        bool p1_state = check(p1->left, p2->right);
        bool p2_state = check(p1->right, p2->left);

        return p1_state && p2_state;
    }

    bool isSymmetric(TreeNode* root) {
        return check(root->left, root->right);
    }
};