/*
題目：
https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/

解說：
使用 sliding windows 概念，由左往右 一一擴增，並且計算 1 出現的次數
當 1 出現 k 次時，左邊開始往右收縮，直到碰到 1

有使用到的觀念：
Sliding Windows
*/

#include "../code_function.h"

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) 
    {
        int left = 0, right = 0, count_1 = 0;
        string small = "";
        
        const int n = s.length();
        while(right < n)
        {
            if(s[right] == '1')
            {
                count_1 ++;
            }
            right++;
            
            if(count_1 == k)
            {
                while(left < right && s[left] != '1') left++;
                string tmp = s.substr(left, right-left);
                left++;
                count_1--;
                
                if(small == "") small = tmp;
                else{
                    if(small.length() > tmp.length()) small = tmp;
                    else if(small.length() == tmp.length()){
                        if(small > tmp) small = tmp;
                    }
                }
            }
            
        }
        
        return small;
    }
};