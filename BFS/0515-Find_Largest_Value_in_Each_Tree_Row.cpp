/*
題目：
https://leetcode.com/problems/find-largest-value-in-each-tree-row/

解說：
使用 BFS 觀念逐層搜索。
使用 queue 紀錄接下來要拜訪的 Node，利用 qsize 紀錄該層有幾個 Node，進行大小比對。
該層比對完之後，將最大值放入 ans 中。
在比較過程中，如果該 Node 有 child 時，將 child 放入 queue 中。
待 qsize 歸零時，queue 內記載的是下一層的 queue。再繼續比較下一層，直到 queue 為空

有使用到的觀念：
BFS, Tree
*/

#include "../code_function.h"

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return {};
        std::queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int q_size = q.size();
            int layer_max = INT_MIN;
            while(q_size--)
            {
                TreeNode* tmp = q.front();
                q.pop();
                int val = tmp->val;
                
                layer_max = max(layer_max, val);
                if(tmp->left)q.push(tmp->left);
                if(tmp->right)q.push(tmp->right);
            }
            
            ans.push_back(layer_max);
        }
        return ans;
    }
};