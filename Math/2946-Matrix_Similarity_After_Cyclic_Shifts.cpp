/*
題目：
https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/

解說：
偶數 index 向左移，可以視為第一個行移動到最後一行
奇數 index 向右移，可以視為最後一行移動到第一行

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) 
    {
        vector<vector<int>> final = mat;
        
        for(int i = 0; i < mat.size(); i++)
        {
            if(i%2 != 0)
            {
                for(int j = 0; j < k; j++)
                {
                    int last = mat[i][mat[i].size()-1];
                    mat[i].pop_back();
                    mat[i].insert(mat[i].begin(), last);
                }
            }else
            {
                for(int j = 0; j < k; j++)
                {
                    int first = mat[i][0];
                    mat[i].erase(mat[i].begin());
                    mat[i].push_back(first);
                }
            }
        }

        return mat == final;
    }
};