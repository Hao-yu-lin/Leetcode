/*
題目：
https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

解說：
解法 1 使用 BFS，先使用 ump 建立每一個點的圖，之後從 target 開始搜索

解法 2 使用 recursion

有使用到的觀念：

*/

#include "../code_function.h"

class Solution1 {
    unordered_map<TreeNode*, vector<TreeNode*>> ump;
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        buildGraph(nullptr, root);
        vector<int> ans;
        vector<bool> seen(501, false);

        queue<TreeNode*> q;
        seen[target->val] = true;

        q.push(target);
        int count = 0;
        while(!q.empty() && count <= k)
        {
            int size = q.size();
            while(size--)
            {
                TreeNode* node = q.front();
                q.pop();
                if(count == k)
                { 
                    ans.push_back(node->val);
                    continue;
                }
                for(TreeNode* next: ump[node])
                {
                    if(seen[next->val] == true) continue;
                    q.push(next);
                    seen[next->val] = true;
                }
            }
            count++;
        }

        return ans;
    }

    void buildGraph(TreeNode* parent, TreeNode* child)
    {
        if(parent)
        {
            ump[parent].push_back(child);
            ump[child].push_back(parent);
        }

        if(child->left) buildGraph(child, child->left);
        if(child->right) buildGraph(child, child->right);
    }
};

class Solution2 {
    vector<int> ans;
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        dist(root, target, k);
        return ans;
    }

    // return the distance from root to target
    // return -1 if target does not in the tree
    int dist(TreeNode* root, TreeNode* target, int k)
    {
        if(root == nullptr) return -1;
        if(root == target)
        {
            collect(target, k);
            return 0;
        }

        int left = dist(root->left, target, k);
        int right = dist(root->right, target, k);

        // target in the right subtree
        if(left >= 0)
        {
            if(left == k-1) ans.push_back(root->val);
            collect(root->right, k - left - 2);
            return left+1;
        }

        if(right >= 0)
        {
            if(right == k-1) ans.push_back(root->val);
            collect(root->left, k - right - 2);
            return right + 1;
        }

        return -1;
    }

    void collect(TreeNode* root, int d)
    {
        if(root == nullptr || d < 0) return;
        if(d == 0) ans.push_back(root->val);
        collect(root->left, d-1);
        collect(root->right, d-1);
    }
};