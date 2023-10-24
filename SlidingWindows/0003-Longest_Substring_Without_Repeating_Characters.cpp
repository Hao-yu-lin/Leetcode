/*
題目：
https://leetcode.com/problems/longest-substring-without-repeating-characters/

解說：
使用 set 不會儲存重複元素的特性。
藉由比較 set 與 sliding windows 大小，來判斷目前的 subarray 是否為不重複子集。
如果有重複子集，最左邊的向右，縮小 sliding windows。

有使用到的觀念：
Sliding Windows, Set, String
*/

#include "../code_function.h"

class Solution {
public:
    int lengthOfLongestSubstrings(string s) 
    {
        int maxLen = 0;

        set<char> st;
        int left = 0, right = 0;
        while(left <= right && right < s.length())
        {
            st.insert(s[right]);
            if(st.size() == (right - left + 1))
            {
                maxLen = std::max(maxLen, right-left+1);
                right++;
            }else
            {
                st.erase(s[left]);
                left ++;
            }
        }
        return maxLen;
    }
};