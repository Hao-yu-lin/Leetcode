/*
題目：
https://leetcode.com/problems/binary-tree-level-order-traversal/

解說：
使用 BFS 觀念逐層搜索。
使用 queue 紀錄接下來要拜訪的 Node，利用 qsize 紀錄該層有幾個 Node，
建立一個 vector 紀錄該層的 Node->val，如果該 Node 有 child 時，將 child 放入 queue 中，
因為題目是 level order，因此放入 queue 的順序需注意，先放 left child 再放 right child
待 qsize 歸零時，queue 內記載的是下一層的 queue。
將該層的 vector  放入 ans 後，繼續往下一層探索。


有使用到的觀念：
BFS, Tree
*/

#include "../code_function.h"

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if(root == nullptr) return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty())
        {
            size_t qsize = q.size();
            vector<int> level;
            while(qsize--)
            {
                TreeNode* tmp = q.front();
                q.pop();
                level.push_back(tmp->val);
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};