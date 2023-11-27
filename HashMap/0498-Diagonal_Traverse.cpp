/*
題目：
https://leetcode.com/problems/diagonal-traverse/description/

解說：
使用 hash table 儲存 i+j 位置的值

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) 
    {
        const int m = mat.size();
        const int n = mat[0].size();

        vector<vector<int>> cnt;
        for(int i = 0; i < m+n; i++)
        {
            cnt.push_back({});
        }

        for(int i = 0;i < m; i++)
            for(int j = 0; j < n; j++)
            {
                cnt[i+j].push_back(mat[i][j]);
            }

        vector<int> ans;
        for(int i = 0; i < m+n; i++)
        {
            for(int j = cnt[i].size()-1; j >= 0; j--)
            {
                ans.push_back(cnt[i][j]);
            }

            i++;
            if(i >= m+n) break;
            for(int j = 0; j < cnt[i].size(); j++)
            {
                ans.push_back(cnt[i][j]);
            }
        }

        return ans;
    }
};