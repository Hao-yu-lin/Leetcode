/*
題目：
https://leetcode.com/problems/gas-station/

解說：


有使用到的觀念：
Greedy, Array
*/

#include "../code_function.h"

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        const int n = gas.size();
        int gas_sum = 0, cost_sum = 0;
        for(int i = 0; i < n ; i++)
        {
            gas_sum += gas[i];
            cost_sum += cost[i];
        }

        if(gas_sum < cost_sum) return -1;

        int start = 0;
        int remain = 0;

        for(int i = 0; i < n; i++)
        {
            if(remain + gas[i] < cost[i])
            {
                start = i+1;
                remain = 0;
            }else{
                remain = remain + gas[i] - cost[i];
            }
        }

        return start;
    }
};