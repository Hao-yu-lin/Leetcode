/*
題目：
https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/

解說：
使用 sliding windows，大小為 k
計算 windows 中的 white 數量，取最少的 white 數量

有使用到的觀念：
Sliding Windows
*/

#include "../code_function.h"

class Solution {
public:
    int minimumRecolors(string blocks, int k) 
    {
        int w_count = 0;
        int b_count = 0;
        int end = 0;
        int start = 0;
        int curr_min = INT_MAX;
        const int n = blocks.length();

        while(end < n)
        {         
            if(blocks[end] == 'B') b_count++;
            else w_count++;
            
            if((end-start+1) == k)
            {
                curr_min = min(curr_min, w_count);
            }
            
            if((end-start+1) > k)
            {
                if(blocks[start] == 'B') b_count--;
                else w_count--;
                start++;
                curr_min = min(curr_min, w_count);
            }
            end++;
        }
        
        return curr_min;
    }
};