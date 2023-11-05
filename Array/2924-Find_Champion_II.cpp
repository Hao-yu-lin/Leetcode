/*
題目：
https://leetcode.com/problems/find-champion-ii/description/

解說：
尋找 indegree 為 0 的即可

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        const int m = edges.size();
        vector<int> inedge(n, 0);
        
        for(int i = 0; i < m; i++)
        {
            inedge[edges[i][1]] ++;
        }
        int count = 0;
        int indx = -1;
        
        for(int i = 0; i < n; i++)
        {
            if(inedge[i] == 0){
                count++;
                indx = i;
            }
        }
        
        if(count == 1) return indx;
        else return -1;
    }
};