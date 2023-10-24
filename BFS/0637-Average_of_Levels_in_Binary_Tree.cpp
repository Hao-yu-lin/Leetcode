/*
題目：
https://leetcode.com/problems/average-of-levels-in-binary-tree/description

解說：
使用 BFS 觀念逐層搜索。
使用 queue 紀錄接下來要拜訪的 Node，利用 qsize 紀錄該層有幾個 Node
額外拷貝一個 qsize，作為等等計算平均時使用，建立一個 sum 型態為 long long。
使用 long long 的原因是怕 sum 時會 overfitting。

在加總的過程中，如果該 Node 有 child 時，將 child 放入 queue 中。
待 qsize 歸零時，queue 內記載的是下一層的 queue。
進行 avg 的計算，將計算結果放入 vector 中
再繼續計算下一層，直到 queue 為空

有使用到的觀念：
BFS, Tree
*/

#include "../code_function.h"
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) 
    {
        if(root == nullptr) return {0.0};
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int qsize = q.size();
            int len = qsize;
            long long sum = 0;
            while(qsize--)
            {
                TreeNode* tmp = q.front();
                q.pop();
                sum+= tmp->val;
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
            double avg = sum/(double)len;
            ans.push_back(avg);
        }
        return ans;
    }
};