/*
題目：
https://leetcode.com/problems/intervals-between-identical-elements/

解說：
先將相同 arr[i] 的進行 index 分類，之後針對每一個分類進行計算
利用類似於 1685 觀念，計算該 index 數組裡所有元素到某一個元素的絕對值差之和。

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) 
    {
        const int n = arr.size();
        unordered_map<int, vector<int>> ump;
        for(int i = 0; i < n; i++)
        {
            ump[arr[i]].push_back(i);
        }
        vector<long long> ans(n ,0);
        for(auto x : ump)
        {
            int val = x.first;
            auto pos = x.second;

            for(int x : pos)
            {
                ans[pos[0]] += x - pos[0];
            }

            for(int i = 1; i < pos.size(); i++)
            {
                ans[pos[i]] = ans[pos[i-1]] + (pos[i] - pos[i-1]) * i - (pos[i] - pos[i-1]) * (pos.size() - i);
            }
        }

        return ans;
    }
};

/*



*/