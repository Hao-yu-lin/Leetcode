/*
題目：
https://leetcode.com/problems/add-binary/

解說：
記得使用一個 carry 作為是否進位的判斷

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    string addBinary(string a, string b) 
    {
        int curr_a = a.length()-1;
        int curr_b = b.length()-1;
        int carry = 0;
        int sum = 0;
        string ans = "";

        while(curr_a >= 0 || curr_b >= 0)
        {
            sum = carry;
            if(curr_a >= 0)
            {
                sum += a[curr_a] - '0';
                curr_a --;
            }

            if(curr_b >= 0)
            {
                sum += b[curr_b] - '0';
                curr_b --;
            }

            ans = to_string(sum % 2) + ans;
            carry = sum/2;
        }

        if(carry)
            ans = to_string(carry) + ans;
        
        return ans;
    }
};