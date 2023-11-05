/*
題目：
https://leetcode.com/problems/find-champion-i/description/

解說：
因為只會 i > j 或 j > i，且只會有一個冠軍，因此假設 0 teams 是冠軍，開始比較遇到強的則將該數設定為新的冠軍

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int champ = 0;
        const int n = grid.size();
        for(int i = 1; i < n; i++)
        {
            if(grid[champ][i] == 0)
                champ = i;
        }

        return champ;
    }
};