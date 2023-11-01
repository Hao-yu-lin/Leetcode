/*
題目：
https://leetcode.com/problems/binary-tree-maximum-path-sum/

解說：
檢查左右節點可以得到的最大 sum，因為要不斷更新 ans 因此使用參考

有使用到的觀念：
Recursion
*/

#include "../code_function.h"

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int ans = INT_MIN;
        maxSum(root, ans);
        return ans;
    }

    int maxSum(TreeNode* root, int& ans)
    {
        if(root == nullptr) return 0;
        int left = max(0, maxSum(root->left, ans));
        int right = max(0, maxSum(root->right, ans));

        int sum = left + right + root->val;
        ans = max(ans ,sum);
        return max(left, right) + root->val;
    }
};