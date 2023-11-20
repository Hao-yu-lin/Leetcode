/*
題目：
https://leetcode.com/problems/diameter-of-binary-tree/

解說：
使用 DFS 方式，左右探詢回傳左右最長的路徑，並且比較由左到右的最長

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
    int ans = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) 
    {
       diameter(root);
       return ans-1;
    }

    int diameter(TreeNode* root)
    {
        if(root == nullptr) return 0;
        int left = diameter(root->left);
        int right = diameter(root->right);

        ans = max(ans, left + right + 1);

        return max(left, right)+1;
    }
};