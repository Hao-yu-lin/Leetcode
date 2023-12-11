/*
題目：
https://leetcode.com/problems/minimize-deviation-in-array/description/

解說：
對於奇數 x 可以轉換成 2x，對於偶數 x 可以變換成 x, x/2, x/4 .... 直到奇數
因此將每一個數組變換看作為同一組
[1, 2, 4, 8]
[3, 6, 12]
[5, 10, 20]
從每一個數組內取一個數，使得所取數的 range 最小，因此就轉換成與 632 同一類型的題目
multiset 內存的是每一數組的最大值，deviation = max(multiset) - min(multiset)


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int minimumDeviation(vector<int>& nums) 
    {
        multiset<int> ms;

        for(auto x : nums)
        {
            if(x%2 == 0)
                ms.insert(x);
            else
                ms.insert(x*2);
        }

        int ans = INT_MAX;
        while(1)
        {
            ans = min(ans, *ms.rbegin() - *ms.begin());
            int m = *ms.rbegin();
            ms.erase(ms.find(m));

            if(m%2 == 0)
                ms.insert(m/2);
            else
                break;
        }

        return ans;
    }
};