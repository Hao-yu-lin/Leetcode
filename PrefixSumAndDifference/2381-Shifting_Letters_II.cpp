/*
題目：
https://leetcode.com/problems/shifting-letters-ii/

解說：
此題為差分數組的題型

因為 diff[i] 可能很大或很小，使用 diff[i]%26 使得範圍落在 [-26, 25]
(diff[i]%26) + 26 -> [0, 51] % 26 -> [0, 25]

有使用到的觀念：
差分數組
*/

#include "../code_function.h"

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) 
    {
        int n = s.size();

        vector<int>diff(n+1);

        for(auto& shif : shifts)
        {
            int a = shif[0], b = shif[1], dir = shif[2];
            int delta =  (dir == 1 ? 1 : -1);
            diff[a] += delta;
            diff[b+1] -= delta;
        }

        int netGain = 0;
        string ans;

        for(int i = 0; i < n; i++)
        {
            netGain = (netGain + (diff[i]%26 + 26) %26)%26;
            ans.push_back('a' + (s[i]-'a' + netGain) % 26);
        }

        return ans;
    }
};