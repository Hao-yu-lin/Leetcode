/*
題目：
https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

解說：
因為要平衡樹高，代表左右子樹的數量必須相同，且必須是 Binary Search Tree
因此先將 nums 由小到大排序後，從中間頗半，左邊的陣列接左子樹，右邊的陣列接右子樹

有使用到的觀念：
Divide and Conquer, Binary Tree
*/

#include "../code_function.h"

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return nullptr;
        if(nums.size() == 1) return new TreeNode(nums[0]);

        int middle = nums.size()/2;

        TreeNode* root = new TreeNode(nums[middle]);

        vector<int> left(nums.begin(), nums.begin()+middle);
        vector<int> right(nums.begin()+middle+1, nums.end());

        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);

        return root;
    }
};