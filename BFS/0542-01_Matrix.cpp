/*
題目：
https://leetcode.com/problems/01-matrix/

解說：
使用 dist 紀錄最靠近 0 的距離
先由左上至右下，比對左邊或上面，最靠近 0 的值為多少，此時 dist 所呈現的是左側最小值
再從右下到左上，審視右側是否有更近的值

有使用到的觀念：
BFS
*/

#include "../code_function.h"

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX/2));

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                if(mat[i][j] == 0) dist[i][j] = 0;
                else
                {
                    if(i > 0) 
                        dist[i][j] = min(dist[i][j], dist[i-1][j] + 1);
                    if(j > 0)
                        dist[i][j] = min(dist[i][j], dist[i][j-1] + 1);
                }
            }

        for(int i = m-1; i >= 0; i--)
            for(int j = n-1; j >= 0; j--)
            {
                if(i < m-1)
                    dist[i][j] = min(dist[i][j], dist[i+1][j] + 1);
                if(j < n-1)
                    dist[i][j] = min(dist[i][j], dist[i][j+1] + 1);
            }

        return dist;
    }
};