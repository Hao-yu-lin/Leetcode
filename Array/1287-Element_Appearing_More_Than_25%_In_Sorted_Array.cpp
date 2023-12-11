/*
題目：
https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) 
    {
        const int n = arr.size();
        int times = n/4;
        int curr_cnt = 0;
        int curr_num = arr[0];

        for(auto i : arr)
        {
            if(curr_num == i)
            {
                curr_cnt ++;
                if(curr_cnt > times) return curr_num;
            }else
            {
                curr_num = i;
                curr_cnt = 1;
            }
        }

        return curr_num;

    }
};