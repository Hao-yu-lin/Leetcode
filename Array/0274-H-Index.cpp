/*
題目：
https://leetcode.com/problems/h-index/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();

        sort(citations.rbegin(), citations.rend());
        int h_index = 0;
        for(int i = 0; i < n; i++){
            if(citations[h_index] > h_index) h_index ++;
        }

        return h_index;
    }
};