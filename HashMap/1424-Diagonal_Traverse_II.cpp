/*
題目：
https://leetcode.com/problems/diagonal-traverse-ii/description/

解說：
解法1 跟 2 是同樣的概念，只是改用不同的 stl
因為對角線抓取，將 i+j 值相同的擺放一起，因此使用 hashtable 紀錄值

有使用到的觀念：

*/

#include "../code_function.h"

class Solution1 {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) 
    {
        map<int, stack<int>> ump;

        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < nums[i].size(); j++)
            {
                int pos = i+j;
                ump[pos].push(nums[i][j]);
            }
        }

        vector<int> ans;
        for(auto& p : ump)
        {
            while(!p.second.empty())
            {
                ans.push_back(p.second.top());
                p.second.pop();
            }
        }

        return ans;
    }
};

class Solution2 {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) 
    {
        unordered_map<int, vector<int>> ump;
        int maxkey = -1;

        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < nums[i].size(); j++)
            {
                int pos = i+j;
                ump[pos].push_back(nums[i][j]);
                maxkey = max(maxkey, pos);
            }
        }

        vector<int> ans;
        for(int i = 0; i <= maxkey; i++)
        {
            int size = ump[i].size();

            for(int j = size-1; j >= 0; j--)
            {
                ans.push_back(ump[i][j]);
            }
        
        }

        return ans;
    }
};