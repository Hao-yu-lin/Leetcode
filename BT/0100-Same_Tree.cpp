/*
題目：
https://leetcode.com/problems/same-tree/

解說：
使用兩個 queue ，將個別 node 依序放入。再取出看是否相等

有使用到的觀念：
queue
*/

#include "../code_function.h"

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {

        queue<TreeNode*> queue_p;
        queue<TreeNode*> queue_q;
        
        queue_p.push(p);
        queue_q.push(q);

        while(!queue_p.empty() && !queue_q.empty())
        {
            TreeNode* tmp_p = queue_p.front();
            queue_p.pop();

            TreeNode* tmp_q = queue_q.front();
            queue_q.pop();

            if(tmp_p == nullptr && tmp_q == nullptr) continue;
            if(tmp_p == nullptr || tmp_q == nullptr) return false;

            if(tmp_p->val != tmp_q->val) return false;

            queue_p.push(tmp_p->left);
            queue_q.push(tmp_q->left);

            queue_p.push(tmp_p->right);
            queue_q.push(tmp_q->right);
        }

        return true;
    }
};