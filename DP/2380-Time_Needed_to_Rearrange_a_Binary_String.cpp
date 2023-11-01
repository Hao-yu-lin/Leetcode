/*
題目：
https://leetcode.com/problems/time-needed-to-rearrange-a-binary-string/

解說：
01 -> 10 可以看成 1 往前一格，因此形成 111...100...0 這樣的排列方式
因此重點是在字串中，最後一個1抵達位置的步數
000 ... 1 000 1
count = the number of zeros before j

f[j] = max(f[i]+1, count)
因為會受到前面的 1 往前比較慢，而造成阻塞

init:001101
010110      <- 此時f[4] 受到 f[3] 造成阻塞 
101010
110100

有使用到的觀念：
DP
*/

#include "../code_function.h"

class Solution {
public:
    int secondsToRemoveOccurrences(string s) 
    {
        const int n = s.size();
        int count = 0;
        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == '0')
                count++;
            else
            {
                if(count > 0)
                    ans = max(ans+1, count);
            }
        }
        return ans;
    }
};