/*
題目：
https://leetcode.com/problems/fraction-to-recurring-decimal/

解說：
需要注意幾個問題
1. 被除數為 0
2. 被除數或除數為負數
3. INT_MIN 取絕對值時會溢出
4. 整除

透過一個 hash map 紀錄每次餘數的位置，如果餘數已經在 hash map ，則代表有循環

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) 
    {
        long A = numerator;
        long B = denominator;

        if(A == 0) return "0";

        int sign = 1;
        if(A < 0)
        {
            sign *= -1;
            A = abs(A);
        }

        if(B < 0)
        {
            sign *= -1;
            B = abs(B);
        }

        string ans = "";
        if(sign == -1) ans += "-";
        ans += to_string(A/B);

        if(A % B == 0) return ans;
        else ans += ".";

        long C = A%B;
        unordered_map<int, int> ump;
        while(C != 0 && ump.find(C) == ump.end())
        {
            ump[C] = ans.length();
            ans += ('0'+C*10/B);
            C = C*10%B;
        }

        if(C == 0) return ans;

        ans.insert(ans.begin()+ump[C], '(');
        ans += ')';

        return ans;
    }
};