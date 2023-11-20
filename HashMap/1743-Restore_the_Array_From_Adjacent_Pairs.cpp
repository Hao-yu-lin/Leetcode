/*
題目：
https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/

解說：
因為只記錄相鄰的點，因此使用 hashmap 紀錄相鄰的點，找到只存一個相鄰點的 hashmap
代表該點為兩側邊界，任選一個邊界，開始建構整個 array

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
    unordered_map<int, vector<int>> ump;
    vector<int> ans;
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) 
    {
        const int n = adjacentPairs.size();
        
        for(const auto& p : adjacentPairs)
        {
            ump[p[0]].push_back(p[1]);
            ump[p[1]].push_back(p[0]);
        }

        for(auto &p : ump)
        {
            if(p.second.size() == 1)
            {
                ans.push_back(p.first);
                search(p.first, p.second[0]);
                break;
            }
        }
        
        return ans;
    }

    void search(int prev, int curr)
    {
        ans.push_back(curr);
        if(ump[curr].size() == 1) return;
        int tmp = ump[curr][0] == prev ? ump[curr][1] : ump[curr][0];
        search(curr, tmp);
    }
};