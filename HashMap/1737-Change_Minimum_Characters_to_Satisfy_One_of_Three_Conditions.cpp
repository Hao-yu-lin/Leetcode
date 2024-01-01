/*
題目：
https://leetcode.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions/

解說：
將全部出現的字母次數，透過 vector 紀錄起來
透過界線法
- cond1, cond2
以 cond1 為例，以 'c' 為界線，在 cnt_a 中小於 'c' 的次數累加起來，在 cnt_b 中大於 'c' 的次數累加起來
累加的數值代表需替換的次數。

- cond3
將 cnt_a 與 cnt_b 中，不等於該界線值的次數，全部累加起來

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int minCharacters(string a, string b) 
    {
        vector<int> cnt_a(26, 0);
        vector<int> cnt_b(26, 0);

        for(char &c : a)
            cnt_a[c-'a']++;
        for(char &c : b)
            cnt_b[c-'a']++;
        int ans = INT_MAX;

        for(int curr = 0; curr < 26; curr++)
        {
            int change = 0;
            if(curr > 0) // the smallest alphabet is a
            {
                // condition 2.
                change = 0;
                for(int i = 0; i < curr; i++)
                    change += cnt_a[i];
                for(int i = curr; i < 26; i++)
                    change += cnt_b[i];

                ans = min(ans, change);

                // condition 1.
                change = 0;
                for(int i = 0; i < curr; i++)
                    change += cnt_b[i];
                for(int i = curr; i < 26; i++)
                    change += cnt_a[i];

                ans = min(ans, change);
            }

            change = 0;
            for(int i = 0; i < 26; i++)
            {
                if(i != curr)
                {
                    change += cnt_a[i];
                    change += cnt_b[i];
                }
            }
            ans = min(ans, change);
        }    

        return ans;
    }
};