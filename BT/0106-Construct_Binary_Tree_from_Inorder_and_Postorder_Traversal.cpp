/*
題目：
https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

解說：


有使用到的觀念：
Hash Map, Divide and Conquer

*/

#include "../code_function.h"

class Solution {
private:
    unordered_map<int, int> index;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        int inStart = 0, inEnd = inorder.size()-1;
        int posStart = 0, posEnd = postorder.size()-1;

        for(int i = 0; i < inorder.size(); i++){
            index[inorder[i]] = i;
        }
        return build(inorder, postorder, inStart, inEnd, posStart, posEnd);
    }

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int posStart, int posEnd){
        if(inStart > inEnd || posStart > posEnd){
            return nullptr;
        }

        int rootVal = postorder[posEnd];
        TreeNode* root = new TreeNode(rootVal);
        int root_index = index[rootVal];
        int left = root_index - inStart;
        root->left = build(inorder, postorder, inStart, root_index-1, posStart, posStart + left - 1);
        root->right = build(inorder, postorder, root_index + 1, inEnd, posStart + left, posEnd-1);
        return root;
    }
};