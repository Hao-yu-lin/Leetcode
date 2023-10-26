/*
題目：
https://leetcode.com/problems/group-anagrams/

解說：
將每一個字排序後，放入 hash map 內

有使用到的觀念：
Hash Map, Sort
*/

#include "../code_function.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string>> ump;

        for(auto& c : strs)
        {
            string s = c;
            sort(s.begin(), s.end());
            ump[s].push_back(c);
        }

        vector<vector<string>> ans;
        for(auto v : ump)
        {
            ans.push_back(v.second);
        }

        return ans;
    }
};