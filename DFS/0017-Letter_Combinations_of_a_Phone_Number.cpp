/*
題目：
https://leetcode.com/problems/letter-combinations-of-a-phone-number/

解說：
使用 Hash Map 建立每一個按鍵與英文數字的對應，接著透過 DFS 方式找到每一種可能性

有使用到的觀念：
Hash Map
*/

#include "../code_function.h"

class Solution {
    vector<string> ans;
    int n;
    unordered_map<char, vector<char>> ump;
public:
    vector<string> letterCombinations(string digits) 
    {
        n = digits.length();
        if(n == 0) return {};
        ump['2'] = {'a', 'b', 'c'};
        ump['3'] = {'d', 'e', 'f'};
        ump['4'] = {'g', 'h', 'i'};
        ump['5'] = {'j', 'k', 'l'};
        ump['6'] = {'m', 'n', 'o'};
        ump['7'] = {'p', 'q', 'r', 's'};
        ump['8'] = {'t', 'u', 'v'};
        ump['9'] = {'w', 'x', 'y', 'z'};
        
        dfs(digits, 0, "");
        return ans;
    }

    void dfs(string& digits, int curr, string tmp)
    {
        if(curr == n)
        {
            ans.push_back(tmp);
            return;
        }
        
        for(auto& c : ump[digits[curr]])
        {
            dfs(digits, curr+1, tmp+c);
        }
        
    }
};