/*
題目：
https://www.hackerrank.com/challenges/angry-children/problem?isFullScreen=false

解說：


有使用到的觀念：

*/

#include "../code_function.h"

int maxMin(int k, vector<int> arr) 
{
    sort(arr.begin(), arr.end());
    int ans = INT_MAX;
    for(int i = 0; i < arr.size()-k+1; i++)
    {
        int diff = arr[i+k-1] - arr[i];
        ans = min(ans, diff);
    }
    
    return ans;
}