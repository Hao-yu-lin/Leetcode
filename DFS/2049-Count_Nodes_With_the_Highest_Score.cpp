/*
題目：
https://leetcode.com/problems/count-nodes-with-the-highest-score/

解說：
本質是設計一個遞迴，計算 node 為 root的子樹包含的元素個數。
如果刪除該 node ，剩下的三個部分為 dfs(node->left), dfs(node->right), n-1-dfs(node->left)-dfs(node->right)
把這三個非零元素相乘，就是一個score

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
    vector<vector<int>> children;
    unordered_map<long long, int>ump;
public:
    int countHighestScoreNodes(vector<int>& parents) 
    {
        const int n = parents.size();
        children.resize(n);

        for(int i = 1; i < n; i++)
            children[parents[i]].push_back(i);

        dfs(0);
        long long maxKey = -1;
        int count = 0;
        for(auto x : ump)
        {
            if(x.first > maxKey)
            {
                maxKey = x.first;
                count = x.second;
            }
        }

        return count;
    }

    int dfs(int node) // the number of nodes in subtree rooted at node
    {
        int n = children.size();
        vector<int> sub;
        int sub_total = 0;
        for(int child : children[node])
        {
            sub.push_back(dfs(child));
            sub_total += sub.back();
        }

        long long score = 1;
        if(n-1-sub_total > 0)
            score *= n - 1 - sub_total;
        for(int x : sub)
            if(x > 0)score *= x;
        ump[score] ++;
        return sub_total+1;
    }
};