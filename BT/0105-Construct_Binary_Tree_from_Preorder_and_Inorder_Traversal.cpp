/*
題目：
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

解說：


有使用到的觀念：
Hash Map, Divide and Conquer
*/

#include "../code_function.h"

class Solution {
    unordered_map<int, int> ump;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int preStart = 0, preEnd = preorder.size()-1;
        int inStart = 0, inEnd = inorder.size()-1;

        for(int i = 0; i < inorder.size(); i++)
        {
            ump[inorder[i]] = i;
        }
        return construct(preorder, inorder, preStart, preEnd, inStart, inEnd);
    }

    TreeNode* construct(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd)
    {
        if(preStart > preEnd || inStart > inEnd) return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int rootIndex = ump[root->val];
        int leftelem = rootIndex - inStart;

        root->left = construct(preorder, inorder, preStart+1, preStart+leftelem, inStart, rootIndex-1);
        root->right = construct(preorder, inorder, preStart+leftelem+1, preEnd, rootIndex+1, inEnd);

        return root;
    }
};