/*
題目：
https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/

解說：
使用 vector<pair<int,int>> 計算每一個 bit 出現次數
之後使用 sort  來排序

有使用到的觀念：
Bit Manipulation
*/

#include "../code_function.h"

class Solution {
public:
    int countBits(int n)
    {
        int count = 0;
        while(n>0)
        {
            n = n & (n-1);
            count++;
        }

        return count;
    }

    vector<int> sortByBits(vector<int>& arr) 
    {
        vector<pair<int, int>> bits;
        for(auto x : arr)
        {
            int count = countBits(x);
            bits.push_back({count, x});
        }

        sort(bits.begin(), bits.end());
        vector<int>ans;
        for(auto x : bits)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};