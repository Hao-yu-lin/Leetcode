/*
題目：
https://www.hackerrank.com/challenges/equal/problem

解說：


有使用到的觀念：

*/

#include "../code_function.h"

int equal(vector<int> arr) {
    sort(arr.begin(), arr.end());
    int min_val = arr[0];
    int min_oper = INT_MAX;
    
    for(int i = 0; i < 5; i++)
    {
        int now = 0;
        for(auto& x : arr)
        {
            int t = x - min_val;
            now += t/5;
            t = t % 5;
            now += t/2;
            t = t % 2;
            now += t%2;
        }
        
        min_oper = min(min_oper, now);
        min_val --;
    }
    return min_oper;
}