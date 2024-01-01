/*
題目：
https://leetcode.com/problems/number-of-possible-sets-of-closing-branches/

解說：
因為節點數只有 10個，可以暴力枚舉所有 closure 放案，利用 n bits 代表每一種可能，只需要 2^n 種
對於每一種 closure 方案，可以使用 floy algo 計算出任意兩點間的最短距離，最後檢查是否都小於 maxDistance

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) 
    {
        int ans = 0;
        for(int state = 0; state < (1 << n); state++)
        {
            vector<vector<int>> dist(n, vector<int>(n, INT_MAX/3));

            for(int i = 0; i < n; i++)
            {
                if(((state >> i)&1) == 0) continue;
                dist[i][i] = 0;
            }

            for(auto road : roads)
            {
                int u = road[0], v = road[1], w = road[2];
                if(((state >> u)&1) == 0) continue;
                if(((state >> v)&1) == 0) continue;

                for(int i = 0; i < n; i++)
                {
                    if(((state >> i)&1) == 0) continue;
                    for(int j = 0; j < n; j++)
                    {
                        if(((state >> j)&1) == 0) continue;
                        dist[i][j] = min(dist[i][j], dist[i][u] + w + dist[v][j]);
                        dist[i][j] = min(dist[i][j], dist[i][v] + w + dist[u][j]);
                    }
                }
            }

            int flag = 1;
            for(int i = 0; i < n; i++)
            {
                if(((state >> i)&1) == 0) continue;
                for(int j = 0; j < n; j++)
                {
                    if(((state >> j)&1) == 0) continue;
                    if(dist[i][j] > maxDistance)
                    {
                        flag = 0;
                        break;
                    }
                }
                if(flag == 0) break;
            }

            if(flag) ans++;
        }

        return ans;
    }
};