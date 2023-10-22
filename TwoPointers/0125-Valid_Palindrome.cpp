/*
題目：
https://leetcode.com/problems/valid-palindrome/

解說：
將字串中，除了字母與數字以外的數字剔除掉後。
設置左指標與右指標，從邊界往內依依比較，直到碰到。

有使用到的觀念：
Two Pointers, String
*/
#include <string>

class Solution {
public:
    bool isPalindrome(std::string s) 
    {
        std::string tmp = "";
        for(const auto c : s)
        {
            if(isalpha(c))
            {
                tmp += tolower(c);
            }else if(isdigit(c))
            {
                tmp += c;
            }
        }

        for(int i = 0, j = tmp.length()-1; i < j; i++, j--)
        {
            if(tmp[i] != tmp[j]) return false;
        }

        return true;
    }
};