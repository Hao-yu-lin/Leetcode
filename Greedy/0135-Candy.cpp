/*
題目：
https://leetcode.com/problems/candy/

解說：
先由左往右比較，如果 ratings[i] > ratings[i-1] 則檢查 當下的 candy 是否有比左側多(i-1)
同樣的方法由右往左檢查，如果 ratings[i] > ratings[i＋1] 則檢查 當下的 candy 是否有比右側多(i+1)

有使用到的觀念：
Greedy, Array
*/

#include "../code_function.h"

class Solution {
public:
    int candy(vector<int>& ratings) 
    {
        const int n = ratings.size();
        vector<int> get(n, 1);
        for(int i = 1; i < n; i++)
        {
            if(ratings[i] > ratings[i-1])
                get[i] = max(get[i], get[i-1]+1);
        }

        for(int i = n-2; i>= 0; i--)
        {
            if(ratings[i] > ratings[i+1])
                get[i] = max(get[i], get[i+1]+1);
        }
        int total = 0;
        for(int i = 0; i < n; i++)
            total += get[i];
        return total;
    }
};
