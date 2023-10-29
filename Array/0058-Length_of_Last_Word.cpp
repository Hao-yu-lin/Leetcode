/*
題目：
https://leetcode.com/problems/length-of-last-word/

解說：
由右往左找，先將空白刪掉直到遇到倒數第一個字母，之後開始計算直到遇到空白

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        int n = s.length();
        int right = n-1;
        while(right >= 0 && s[right] == ' ')right--;
        int ans = 0;
        while(right >= 0 && s[right] != ' '){
            right--;
            ans++;
        }

        return ans;
    }
};
