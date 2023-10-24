/*
題目：
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

解說：
使用 BFS 觀念逐層搜索。
使用 queue 紀錄接下來要拜訪的 Node，利用 qsize 紀錄該層有幾個 Node，並新增一個紀錄目前是在哪一層的 變數
建立一個 vector 紀錄該層的 Node->val，如果該 Node 有 child 時，將 child 放入 queue 中，
因為題目是 之字，因此放入 queue 的順序需注意，先放 left child 再放 right child
因為是之字型，所以偶數層由左望有，奇數層由右往左。因此奇數層必須反轉。

待 qsize 歸零時，queue 內記載的是下一層的 queue。
將該層的 vector  放入 ans 後，繼續往下一層探索。

有使用到的觀念：
BFS, Tree
*/

#include "../code_function.h"

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int curr_level = 0;
        if(root == nullptr) return {};

        vector<vector<int>> ans;
        queue<TreeNode* >q; 

        q.push(root);

        while(!q.empty()){
            int size = q.size();

            vector<int> level_traversal;
            while(size --){
                TreeNode* temp = q.front();
                q.pop();
                level_traversal.push_back(temp->val);

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

            if(curr_level % 2 == 1){
                reverse(level_traversal.begin(), level_traversal.end());
            }

            ans.push_back(level_traversal);
            curr_level++;
        }

        return ans;
    }
};