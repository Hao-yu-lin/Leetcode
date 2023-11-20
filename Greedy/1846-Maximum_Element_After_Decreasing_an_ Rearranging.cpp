/*
題目：
https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/

解說：
先進行排序後，將第一個數值設定為 1 後，開始逐個檢查是否與前一個相差為 <= 1

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) 
    {
        const int n = arr.size();

        sort(arr.begin(), arr.end());

        arr[0] = 1;
        for(int i = 1; i < n; i++)
        {
            if(arr[i] - arr[i-1] > 1)
            {
                arr[i] = arr[i-1] + 1;
            }
        }
        return arr[n-1];
    }
};