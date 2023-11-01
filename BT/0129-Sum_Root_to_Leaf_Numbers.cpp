/*
題目：
https://leetcode.com/problems/sum-root-to-leaf-numbers/

解說：
方法1：
使用 queue 紀錄目前的 Node 與值，進行 BFS 搜索。

方法2：
使用 Recursion

有使用到的觀念：
BFS, Recursion
*/

#include "../code_function.h"

class Solution1 {
public:
    int sumNumbers(TreeNode* root) 
    {
        if(root == nullptr) return false;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        long long ans = 0;

        while(!q.empty())
        {
            int size = q.size();

            while(size--)
            {
                auto tmp = q.front();
                q.pop();
                TreeNode* node = tmp.first;
                long long val = tmp.second;

                val = val * 10 + node->val;

                if(node->left)
                {
                    q.push({node->left, val});
                }

                if(node->right)
                {
                    q.push({node->right, val});
                }

                if(!node->left && !node->right) ans += val;

            }
        }

        return ans;
    }
};

class Solution2 {
    long long ans = 0;
public:
    int sumNumbers(TreeNode* root) {
        if(root == nullptr) return 0;
        totalsum(root, 0);
        return ans;
    }

    void totalsum(TreeNode* root, long long sum)
    {
        sum = sum* 10 + root->val;
        if(!root->left && !root->right){ 
            ans += sum;
            return;
        }

       

        if(root->left) totalsum(root->left, sum);
        if(root->right) totalsum(root->right, sum);
    }
};