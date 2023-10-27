/*
題目：
https://leetcode.com/problems/maximum-depth-of-binary-tree

解說：
解法一：使用 queue
解法二：使用 recursion，回傳左右子樹的高

有使用到的觀念：
BT, Queue, Recursion
*/

#include "../code_function.h"

class Solution1 {
public:
    int maxDepth(TreeNode* root) 
    {
        if(root == nullptr) return 0;
        int depth = 0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            depth++;
            while(size--)
            {
                TreeNode* tmp = q.front();
                q.pop();

                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
        }

        return depth;
    }
};

class Solution2 {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return max(left, right) + 1;
    }
};